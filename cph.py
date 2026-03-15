#!/usr/bin/env python3
"""
cph.py - Competitive Programming Helper (Dynamic Edition)
Uses official APIs and metadata from online judges for accurate organization.

Data Sources:
    - Codeforces API: Contest types, problem ratings, tags
    - CSES: Topic mapping from problem IDs
    - USACO: Division and contest info from .cph metadata
    - AtCoder: Contest type from group field

Commands:
    move    - Move solved files from root to platform folders
    sort    - Organize files by category (rounds, topics, divisions)
    stats   - Show statistics with API-enriched data
    clean   - Remove empty directories
    fetch   - Download/update contest data from APIs
"""

import os
import re
import sys
import json
import shutil
import argparse
import urllib.request
from pathlib import Path
from datetime import datetime
from collections import defaultdict
from typing import Optional, Dict, List, Tuple, Set

# Configuration
ROOT_DIR = Path(__file__).parent
CPH_DIR = ROOT_DIR / ".cph"
SOLVED_DIR = ROOT_DIR / "solved"
CACHE_DIR = ROOT_DIR / ".cache"
CACHE_FILE = CACHE_DIR / "cf_contests.json"
SOURCE_EXTENSIONS = {'.cpp', '.py', '.java', '.c', '.cc', '.rs', '.go', '.kt'}
_CPH_INDEX = None

# ANSI Colors
class C:
    R = '\033[91m'; G = '\033[92m'; Y = '\033[93m'; B = '\033[94m'
    C = '\033[96m'; M = '\033[95m'; W = '\033[97m'; D = '\033[90m'
    BOLD = '\033[1m'; NC = '\033[0m'

# ============================================================================
#  API CLIENTS - Fetch official data from online judges
# ============================================================================

class CodeforcesAPI:
    """Fetch and cache contest data from Codeforces API."""
    BASE = "https://codeforces.com/api"
    
    @staticmethod
    def fetch_contests() -> Dict[int, Dict]:
        """Fetch all contest metadata. Returns {contest_id: contest_data}"""
        try:
            url = f"{CodeforcesAPI.BASE}/contest.list?gym=false"
            with urllib.request.urlopen(url, timeout=30) as r:
                data = json.loads(r.read().decode())
                if data.get('status') == 'OK':
                    return {c['id']: c for c in data.get('result', [])}
        except Exception as e:
            print(f"{C.D}[API] Could not fetch CF contests: {e}{C.NC}")
        return {}
    
    @staticmethod
    def fetch_gyms() -> Dict[int, Dict]:
        """Fetch gym contest metadata."""
        try:
            url = f"{CodeforcesAPI.BASE}/contest.list?gym=true"
            with urllib.request.urlopen(url, timeout=30) as r:
                data = json.loads(r.read().decode())
                if data.get('status') == 'OK':
                    return {c['id']: c for c in data.get('result', [])}
        except Exception:
            pass
        return {}


class ContestCache:
    """Local cache for API data to avoid repeated requests."""
    
    def __init__(self):
        self.contests: Dict[int, Dict] = {}
        self.gyms: Set[int] = set()
        self._load()
    
    def _load(self):
        """Load cached data from disk."""
        if CACHE_FILE.exists():
            try:
                with open(CACHE_FILE) as f:
                    data = json.load(f)
                    self.contests = {int(k): v for k, v in data.get('contests', {}).items()}
                    self.gyms = set(data.get('gyms', []))
            except:
                pass
    
    def save(self):
        """Save cache to disk."""
        CACHE_DIR.mkdir(exist_ok=True)
        with open(CACHE_FILE, 'w') as f:
            json.dump({
                'contests': self.contests,
                'gyms': list(self.gyms),
                'updated': datetime.now().isoformat()
            }, f, indent=2)
    
    def update(self):
        """Refresh cache from API."""
        print(f"{C.B}Fetching Codeforces contest data...{C.NC}")
        contests = CodeforcesAPI.fetch_contests()
        if contests:
            self.contests = contests
            print(f"  ✓ {len(contests)} contests")
        
        print(f"{C.B}Fetching Codeforces gym data...{C.NC}")
        gyms = CodeforcesAPI.fetch_gyms()
        if gyms:
            self.gyms = set(gyms.keys())
            print(f"  ✓ {len(gyms)} gyms")
        
        self.save()
        print(f"{C.G}Cache updated!{C.NC}")
    
    def get_contest(self, contest_id: int) -> Optional[Dict]:
        """Get contest info by ID."""
        return self.contests.get(contest_id)
    
    def is_gym(self, contest_id: int) -> bool:
        """Check if a contest ID is a gym."""
        return contest_id in self.gyms or contest_id >= 100000
    
    def get_contest_type(self, contest_id: int) -> str:
        """Determine contest category from official data."""
        contest = self.get_contest(contest_id)
        if not contest:
            return "Other"
        
        name = contest.get('name', '')
        
        # Educational rounds
        if 'Educational' in name:
            return 'Edu_Rounds'
        
        # Global rounds
        if 'Global' in name:
            return 'Global'
        
        # Div classification
        if 'Div. 4' in name or 'Div.4' in name:
            return 'Div4'
        if 'Div. 3' in name or 'Div.3' in name:
            return 'Div3'
        if 'Div. 2' in name or 'Div.2' in name:
            return 'Div2'
        if 'Div. 1' in name or 'Div.1' in name:
            return 'Div1'
        
        return 'Other'


# Global cache instance
_cache: Optional[ContestCache] = None

def get_cache() -> ContestCache:
    global _cache
    if _cache is None:
        _cache = ContestCache()
    return _cache


# ============================================================================
#  CSES TOPIC MAPPING - From official CSES problem set structure
# ============================================================================

CSES_TOPICS = {
    # Introductory Problems (24 problems)
    1068: "Intro", 1083: "Intro", 1069: "Intro", 1094: "Intro", 1070: "Intro",
    1071: "Intro", 1072: "Intro", 1092: "Intro", 1617: "Intro", 1618: "Intro",
    1754: "Intro", 1755: "Intro", 2205: "Intro", 2165: "Intro", 1622: "Intro",
    1623: "Intro", 1624: "Intro", 3399: "Intro", 3419: "Intro", 3217: "Intro",
    3311: "Intro", 2431: "Intro", 1743: "Intro", 1625: "Intro",
    
    # Sorting and Searching (35 problems)
    1621: "Sort", 1084: "Sort", 1090: "Sort", 1091: "Sort", 1619: "Sort",
    1629: "Sort", 1640: "Sort", 1643: "Sort", 1074: "Sort", 2183: "Sort",
    2216: "Sort", 2217: "Sort", 1141: "Sort", 1073: "Sort", 1163: "Sort",
    3420: "Sort", 3421: "Sort", 2162: "Sort", 2163: "Sort", 2168: "Sort",
    2169: "Sort", 1164: "Sort", 1620: "Sort", 1630: "Sort", 1631: "Sort",
    1641: "Sort", 1642: "Sort", 1645: "Sort", 1660: "Sort", 1661: "Sort",
    1662: "Sort", 2428: "Sort", 1085: "Sort", 1632: "Sort", 1644: "Sort",
    
    # Dynamic Programming (23 problems)
    1633: "DP", 1634: "DP", 1635: "DP", 1636: "DP", 1637: "DP", 1638: "DP",
    1158: "DP", 1746: "DP", 2413: "DP", 1639: "DP", 3403: "DP", 1744: "DP",
    3359: "DP", 1745: "DP", 1097: "DP", 1093: "DP", 3314: "DP", 1145: "DP",
    1140: "DP", 1653: "DP", 2181: "DP", 2220: "DP", 1748: "DP",
    
    # Graph Algorithms (36 problems)
    1192: "Graph", 1193: "Graph", 1666: "Graph", 1667: "Graph", 1668: "Graph",
    1669: "Graph", 1194: "Graph", 1671: "Graph", 1672: "Graph", 1673: "Graph",
    1195: "Graph", 1197: "Graph", 1196: "Graph", 1678: "Graph", 1679: "Graph",
    1680: "Graph", 1681: "Graph", 1202: "Graph", 1750: "Graph", 1160: "Graph",
    1751: "Graph", 1675: "Graph", 1676: "Graph", 1682: "Graph", 1683: "Graph",
    1684: "Graph", 1686: "Graph", 1691: "Graph", 1692: "Graph", 1693: "Graph",
    1690: "Graph", 1689: "Graph", 1694: "Graph", 1695: "Graph", 1696: "Graph",
    1711: "Graph",
    
    # Range Queries (25 problems)
    1646: "Range", 1647: "Range", 1648: "Range", 1649: "Range", 1650: "Range",
    1651: "Range", 1652: "Range", 1143: "Range", 1749: "Range", 1144: "Range",
    2166: "Range", 2206: "Range", 3304: "Range", 3163: "Range", 1190: "Range",
    3226: "Range", 1734: "Range", 3356: "Range", 2416: "Range", 1664: "Range",
    1739: "Range", 1735: "Range", 1736: "Range", 1737: "Range", 2184: "Range",
    
    # Tree Algorithms (16 problems)
    1674: "Tree", 1130: "Tree", 1131: "Tree", 1132: "Tree", 1133: "Tree",
    1687: "Tree", 1688: "Tree", 1135: "Tree", 1136: "Tree", 1137: "Tree",
    1138: "Tree", 2134: "Tree", 1139: "Tree", 2079: "Tree", 2080: "Tree",
    2081: "Tree",
    
    # Mathematics (38 problems)
    2164: "Math", 1095: "Math", 1712: "Math", 1713: "Math", 1081: "Math",
    1082: "Math", 2182: "Math", 2185: "Math", 2417: "Math", 3396: "Math",
    1079: "Math", 1715: "Math", 1716: "Math", 1717: "Math", 3397: "Math",
    3398: "Math", 2064: "Math", 2187: "Math", 2209: "Math", 2210: "Math",
    1722: "Math", 1096: "Math", 1723: "Math", 1724: "Math", 3154: "Math",
    3355: "Math", 3406: "Math", 1725: "Math", 1726: "Math", 1727: "Math",
    1728: "Math", 1729: "Math", 1730: "Math", 1098: "Math", 1099: "Math",
    2207: "Math", 2208: "Math",
    
    # String Algorithms (21 problems)
    1731: "String", 1753: "String", 1732: "String", 1733: "String", 1110: "String",
    1111: "String", 3138: "String", 1112: "String", 2420: "String", 2102: "String",
    2103: "String", 2104: "String", 2105: "String", 1149: "String", 2106: "String",
    2107: "String", 3225: "String", 1113: "String", 2108: "String", 2109: "String",
    2110: "String",
    
    # Geometry (16 problems)
    2189: "Geo", 2190: "Geo", 2191: "Geo", 2192: "Geo", 2193: "Geo",
    2194: "Geo", 2195: "Geo", 3410: "Geo", 3411: "Geo", 1740: "Geo",
    3427: "Geo", 3428: "Geo", 3429: "Geo", 3430: "Geo", 1741: "Geo", 1742: "Geo",
    
    # Advanced Techniques (24 problems)
    1628: "Adv", 2136: "Adv", 3360: "Adv", 2137: "Adv", 2138: "Adv",
    2143: "Adv", 2072: "Adv", 2073: "Adv", 2074: "Adv", 2076: "Adv",
    2077: "Adv", 2078: "Adv", 2084: "Adv", 2085: "Adv", 2086: "Adv",
    2087: "Adv", 2088: "Adv", 2111: "Adv", 2112: "Adv", 2113: "Adv",
    2101: "Adv", 2133: "Adv", 2121: "Adv", 2129: "Adv", 2130: "Adv",
    
    # Additional Problems (31 problems)
    1087: "Extra", 3150: "Extra", 3190: "Extra", 1670: "Extra", 3175: "Extra",
    2422: "Extra", 3151: "Extra", 3152: "Extra", 3306: "Extra", 3307: "Extra",
    1142: "Extra", 2186: "Extra", 3169: "Extra", 3193: "Extra", 3294: "Extra",
    3213: "Extra", 3214: "Extra", 2425: "Extra", 3301: "Extra", 3302: "Extra",
    3361: "Extra", 1747: "Extra", 3404: "Extra", 1188: "Extra", 1086: "Extra",
    2427: "Extra", 1147: "Extra", 1162: "Extra", 1191: "Extra", 2414: "Extra",
    1161: "Extra",
}


# ============================================================================
#  CPH FILE PARSER - Extract metadata from .cph/*.prob files
# ============================================================================

class CPHFile:
    """Parses .cph problem files with rich metadata extraction."""
    
    def __init__(self, path: Path):
        self.path = path
        self.data: Dict = {}
        self._load()
    
    def _load(self):
        try:
            with open(self.path, 'r') as f:
                self.data = json.load(f)
        except:
            self.data = {}
    
    @property
    def name(self) -> str:
        return self.data.get('name', '')
    
    @property
    def group(self) -> str:
        return self.data.get('group', '')
    
    @property
    def url(self) -> str:
        return self.data.get('url', '')
    
    @property
    def src_path(self) -> Optional[Path]:
        src = self.data.get('srcPath', '')
        return Path(src) if src else None
    
    @property
    def platform(self) -> str:
        """Detect platform from URL."""
        url = self.url.lower()
        if 'codeforces.com' in url:
            return 'cf'
        if 'cses.fi' in url:
            return 'cses'
        if 'usaco.org' in url or 'usaco.guide' in url:
            return 'usaco'
        if 'atcoder.jp' in url:
            return 'atcoder'
        if 'spoj.com' in url:
            return 'spoj'
        if 'leetcode.com' in url:
            return 'leetcode'
        if 'hackerrank.com' in url:
            return 'hackerrank'
        return 'other'
    
    def extract_cf_contest_id(self) -> Optional[int]:
        """Extract Codeforces contest ID from URL."""
        patterns = [
            r'codeforces\.com/contest/(\d+)',
            r'codeforces\.com/gym/(\d+)',
            r'codeforces\.com/problemset/problem/(\d+)',
        ]
        for p in patterns:
            m = re.search(p, self.url)
            if m:
                return int(m.group(1))
        return None
    
    def extract_cses_id(self) -> Optional[int]:
        """Extract CSES problem ID from URL."""
        m = re.search(r'cses\.fi/problemset/task/(\d+)', self.url)
        return int(m.group(1)) if m else None
    
    def extract_usaco_info(self) -> Dict:
        """Extract USACO division, year, month from group."""
        info = {'division': 'Unknown', 'year': 0, 'month': ''}
        group = self.group
        
        # Division
        if 'Platinum' in group:
            info['division'] = 'Platinum'
        elif 'Gold' in group:
            info['division'] = 'Gold'
        elif 'Silver' in group:
            info['division'] = 'Silver'
        elif 'Bronze' in group:
            info['division'] = 'Bronze'
        
        # Year
        m = re.search(r'20(\d{2})', group)
        if m:
            info['year'] = 2000 + int(m.group(1))
        
        # Month
        for month in ['January', 'February', 'March', 'December', 'Open']:
            if month in group:
                info['month'] = month[:3]
                break
        
        return info
    
    def extract_atcoder_type(self) -> str:
        """Classify AtCoder contest type."""
        group = self.group.upper()
        if 'ABC' in group:
            return 'ABC'
        if 'ARC' in group:
            return 'ARC'
        if 'AGC' in group:
            return 'AGC'
        return 'Other'


# ============================================================================
#  FILE DISCOVERY - Find all source files and their metadata
# ============================================================================

def find_cph_files() -> Dict[Path, CPHFile]:
    """Find files with matching metadata in the workspace."""
    result = {}
    for src_file in find_source_files(ROOT_DIR, recursive=False):
        cph = get_cph_for_file(src_file)
        if cph:
            result[src_file] = cph
    if SOLVED_DIR.exists():
        for src_file in find_source_files(SOLVED_DIR, recursive=True):
            cph = get_cph_for_file(src_file)
            if cph:
                result[src_file] = cph
    return result


def is_source_file(path: Path) -> bool:
    """Check whether a path is a supported source file."""
    return path.is_file() and path.suffix in SOURCE_EXTENSIONS and '.cph' not in path.parts


def find_source_files(directory: Path, recursive: bool = False) -> List[Path]:
    """Find source code files in a directory."""
    if not directory.exists():
        return []

    iterator = directory.rglob('*') if recursive else directory.iterdir()
    return [path for path in iterator if is_source_file(path)]


def invalidate_cph_index():
    """Invalidate the cached metadata index after filesystem updates."""
    global _CPH_INDEX
    _CPH_INDEX = None


def get_cph_index():
    """Build an index of .prob metadata files for fast lookup."""
    global _CPH_INDEX
    if _CPH_INDEX is not None:
        return _CPH_INDEX

    exact = {}
    local_by_name = defaultdict(list)

    for cph_dir in ROOT_DIR.rglob('.cph'):
        if not cph_dir.is_dir():
            continue
        cph_dir_key = str(cph_dir.resolve())
        for prob_file in cph_dir.glob('*.prob'):
            cph = CPHFile(prob_file)
            if cph.src_path:
                exact[str(cph.src_path.resolve())] = prob_file
                local_by_name[(cph_dir_key, Path(cph.src_path).name)].append(prob_file)

    _CPH_INDEX = (exact, local_by_name)
    return _CPH_INDEX


def find_prob_file_for_src(src_file: Path) -> Optional[Path]:
    """Locate the metadata file for a source file.

    Falls back to filename-based matching so previously moved files can still be
    categorized even if their stored srcPath was not updated.
    """
    exact, local_by_name = get_cph_index()
    resolved_src = str(src_file.resolve())

    if resolved_src in exact:
        return exact[resolved_src]

    for parent in (src_file.parent, *src_file.parents):
        cph_dir = parent / '.cph'
        if cph_dir.exists():
            candidates = local_by_name.get((str(cph_dir.resolve()), src_file.name), [])
            if candidates:
                return candidates[0]
        if parent == ROOT_DIR:
            break

    return None


def update_prob_src_path(prob_file: Path, src_file: Path):
    """Rewrite srcPath in a .prob file after moving its source file."""
    try:
        with open(prob_file, 'r') as f:
            data = json.load(f)
        data['srcPath'] = str(src_file)
        with open(prob_file, 'w') as f:
            json.dump(data, f, separators=(',', ':'))
    except Exception:
        pass


def move_file_with_metadata(src_file: Path, dest_file: Path):
    """Move a source file and its matching .prob metadata together."""
    prob_file = find_prob_file_for_src(src_file)

    dest_file.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(src_file), str(dest_file))

    if prob_file:
        dest_prob_dir = dest_file.parent / '.cph'
        dest_prob_dir.mkdir(parents=True, exist_ok=True)
        dest_prob = dest_prob_dir / prob_file.name
        if prob_file.resolve() != dest_prob.resolve():
            shutil.move(str(prob_file), str(dest_prob))
        update_prob_src_path(dest_prob, dest_file)

    invalidate_cph_index()


def get_cph_for_file(src_file: Path) -> Optional[CPHFile]:
    """Find the .cph metadata for a source file."""
    prob_file = find_prob_file_for_src(src_file)
    return CPHFile(prob_file) if prob_file else None


# ============================================================================
#  CF CATEGORIZATION - Using official API data
# ============================================================================

def categorize_cf_problem(cph: Optional[CPHFile]) -> Tuple[str, int]:
    """
    Categorize a CF problem using official API data.
    Returns (category, sort_key).
    
    Categories:
    - R1-1000: Regular rounds 1-1000
    - R1001-2000: Regular rounds 1001-2000
    - Edu_Rounds: Educational rounds
    - Global: Global rounds
    - Div3: Division 3 only contests
    - Div4: Division 4 only contests
    - Gym: Gym contests
    - Other: Everything else
    """
    if not cph:
        return ("Other", 0)
    
    group = cph.group
    url = cph.url
    
    # Extract contest ID
    contest_id = cph.extract_cf_contest_id()
    
    # Check if it's a gym
    if contest_id and contest_id >= 100000:
        return ("Gym", contest_id)
    
    if 'gym/' in url.lower():
        return ("Gym", contest_id or 0)
    
    # Use cached API data
    cache = get_cache()
    if contest_id and cache.contests:
        ctype = cache.get_contest_type(contest_id)
        if ctype == 'Edu_Rounds':
            m = re.search(r'Educational.*?(\d+)', group, re.I)
            return ("Edu_Rounds", int(m.group(1)) if m else contest_id)
        if ctype == 'Global':
            m = re.search(r'Global.*?(\d+)', group, re.I)
            return ("Global", int(m.group(1)) if m else contest_id)
        if ctype in ('Div3', 'Div4'):
            return (ctype, contest_id)
    
    # Fallback to regex parsing
    m = re.search(r'Educational.*?Round\s*(\d+)', group, re.I)
    if m:
        return ("Edu_Rounds", int(m.group(1)))
    
    m = re.search(r'Global.*?Round\s*(\d+)', group, re.I)
    if m:
        return ("Global", int(m.group(1)))
    
    m = re.search(r'Round\s*(\d+)', group, re.I)
    if m:
        round_num = int(m.group(1))
        if round_num <= 1000:
            return ("R1-1000", round_num)
        else:
            return ("R1001-2000", round_num)
    
    if re.search(r'Div\.\s*4|Div\.4', group, re.I):
        return ("Div4", contest_id or 0)
    if re.search(r'Div\.\s*3|Div\.3', group, re.I):
        return ("Div3", contest_id or 0)
    
    return ("Other", contest_id or 0)


# ============================================================================
#  CSES CATEGORIZATION - Using topic mapping
# ============================================================================

def categorize_cses_problem(cph: Optional[CPHFile]) -> str:
    """Categorize CSES problem by topic."""
    if not cph:
        return "Other"
    
    problem_id = cph.extract_cses_id()
    if problem_id:
        return CSES_TOPICS.get(problem_id, "Other")
    
    return "Other"


# ============================================================================
#  USACO CATEGORIZATION - By division and year
# ============================================================================

def categorize_usaco_problem(cph: Optional[CPHFile]) -> Tuple[str, str]:
    """Categorize USACO problem. Returns (division, subfolder)."""
    if not cph:
        return ("Unknown", "")
    
    info = cph.extract_usaco_info()
    division = info['division']
    
    if info['year'] and info['month']:
        subfolder = f"{info['year']}_{info['month']}"
    else:
        subfolder = ""
    
    return (division, subfolder)


# ============================================================================
#  MOVE COMMAND - Move files from root to platform folders
# ============================================================================

def move_files(dry_run: bool = False):
    """Move solved files from root directory to platform folders."""
    print("=" * 50)
    print(f"  {C.BOLD}Moving files to platform folders{C.NC}")
    print("=" * 50)
    
    if dry_run:
        print(f"\n{C.Y}[DRY RUN]{C.NC} No changes will be made\n")
    
    src_files = find_source_files(ROOT_DIR)
    moved = 0
    
    for src_file in src_files:
        cph = get_cph_for_file(src_file)
        if not cph:
            continue
        
        platform = cph.platform
        if platform == 'other':
            continue
        
        dest_dir = SOLVED_DIR / platform
        dest_file = dest_dir / src_file.name
        
        if dest_file.exists():
            print(f"{C.Y}[SKIP]{C.NC} {src_file.name} (exists)")
            continue
        
        print(f"{C.G}[MOVE]{C.NC} {src_file.name} → {platform}/")
        
        if not dry_run:
            move_file_with_metadata(src_file, dest_file)
        moved += 1
    
    print(f"\nMoved {moved} files")


# ============================================================================
#  SORT COMMAND - Organize files within platform folders
# ============================================================================

def sort_cf_files(dry_run: bool = False):
    """Sort CF files into categories using API data."""
    print("\n" + "=" * 50)
    print(f"  {C.BOLD}CF Sorter - Using Official API Data{C.NC}")
    print("=" * 50)
    
    if dry_run:
        print(f"\n{C.Y}[DRY RUN]{C.NC} No changes will be made\n")
    
    cf_dir = SOLVED_DIR / "cf"
    if not cf_dir.exists():
        print("No CF directory found")
        return
    
    files_data = []
    for src_file in find_source_files(cf_dir, recursive=False):
        cph = get_cph_for_file(src_file)
        category, sort_key = categorize_cf_problem(cph)
        files_data.append((src_file, category, sort_key, cph))
    
    print(f"Found {len(files_data)} CF files\n")
    
    categories = defaultdict(list)
    for src_file, category, sort_key, cph in files_data:
        categories[category].append((src_file, sort_key, cph))
    
    for cat in categories:
        categories[cat].sort(key=lambda x: (x[1], x[0].name))
    
    moved = 0
    stats = defaultdict(int)
    
    for category in ['R1-1000', 'R1001-2000', 'Edu_Rounds', 'Global', 'Div3', 'Div4', 'Gym', 'Other']:
        if category not in categories:
            continue
        
        for src_file, sort_key, cph in categories[category]:
            stats[category] += 1
            
            if src_file.parent.name == category:
                continue
            
            dest_dir = cf_dir / category
            dest_file = dest_dir / src_file.name
            
            name_short = src_file.stem[:25]
            key_str = f"#{sort_key}" if sort_key else ""
            print(f"[{category:12}] {key_str:6} {name_short}")
            
            if not dry_run:
                if not dest_file.exists():
                    move_file_with_metadata(src_file, dest_file)
                    moved += 1
    
    print("\n" + "=" * 50)
    summary = ", ".join(f"{k}:{v}" for k, v in sorted(stats.items(), key=lambda x: -x[1]))
    print(f"  {summary}")
    print(f"  Organized {moved} files")
    print("=" * 50)


def sort_cses_files(dry_run: bool = False):
    """Sort CSES files into topic folders."""
    print("\n" + "=" * 50)
    print(f"  {C.BOLD}CSES Sorter - By Topic{C.NC}")
    print("=" * 50)
    
    if dry_run:
        print(f"\n{C.Y}[DRY RUN]{C.NC} No changes will be made\n")
    
    cses_dir = SOLVED_DIR / "cses"
    if not cses_dir.exists():
        print("No CSES directory found")
        return
    
    moved = 0
    stats = defaultdict(int)
    
    for src_file in find_source_files(cses_dir, recursive=False):
        cph = get_cph_for_file(src_file)
        topic = categorize_cses_problem(cph)
        stats[topic] += 1
        
        if src_file.parent.name == topic:
            continue
        
        dest_dir = cses_dir / topic
        dest_file = dest_dir / src_file.name
        
        print(f"[{topic:8}] {src_file.stem[:30]}")
        
        if not dry_run:
            if not dest_file.exists():
                move_file_with_metadata(src_file, dest_file)
                moved += 1
    
    summary = ", ".join(f"{k}:{v}" for k, v in sorted(stats.items(), key=lambda x: -x[1]))
    print(f"\n{summary}")
    print(f"Organized {moved} files")


def sort_usaco_files(dry_run: bool = False):
    """Sort USACO files by division."""
    print("\n" + "=" * 50)
    print(f"  {C.BOLD}USACO Sorter - By Division{C.NC}")
    print("=" * 50)
    
    usaco_dir = SOLVED_DIR / "usaco"
    if not usaco_dir.exists():
        print("No USACO directory found")
        return
    
    moved = 0
    stats = defaultdict(int)
    
    for src_file in find_source_files(usaco_dir, recursive=False):
        cph = get_cph_for_file(src_file)
        division, _ = categorize_usaco_problem(cph)
        stats[division] += 1
        
        if src_file.parent.name == division:
            continue
        
        dest_dir = usaco_dir / division
        dest_file = dest_dir / src_file.name
        
        print(f"[{division:10}] {src_file.stem[:30]}")
        
        if not dry_run:
            if not dest_file.exists():
                move_file_with_metadata(src_file, dest_file)
                moved += 1
    
    summary = ", ".join(f"{k}:{v}" for k, v in sorted(stats.items(), key=lambda x: -x[1]))
    print(f"\n{summary}")
    print(f"Organized {moved} files")


def sort_files(platform: str = "all", dry_run: bool = False):
    """Sort files for specified platform(s)."""
    if platform in ("all", "cf"):
        sort_cf_files(dry_run)
    if platform in ("all", "cses"):
        sort_cses_files(dry_run)
    if platform in ("all", "usaco"):
        sort_usaco_files(dry_run)


# ============================================================================
#  STATS COMMAND - Show detailed statistics
# ============================================================================

def show_stats():
    """Display comprehensive statistics."""
    print("=" * 50)
    print(f"  {C.BOLD}Problem Statistics{C.NC}")
    print("=" * 50)
    
    all_files = find_cph_files()
    
    platforms = defaultdict(int)
    cf_categories = defaultdict(int)
    cses_topics = defaultdict(int)
    usaco_divs = defaultdict(int)
    
    for src, cph in all_files.items():
        plat = cph.platform
        platforms[plat] += 1
        
        if plat == 'cf':
            cat, _ = categorize_cf_problem(cph)
            cf_categories[cat] += 1
        elif plat == 'cses':
            topic = categorize_cses_problem(cph)
            cses_topics[topic] += 1
        elif plat == 'usaco':
            div, _ = categorize_usaco_problem(cph)
            usaco_divs[div] += 1
    
    total = sum(platforms.values())
    print(f"\n{C.BOLD}Total Problems:{C.NC} {total}\n")
    
    print(f"{C.B}By Platform:{C.NC}")
    max_count = max(platforms.values()) if platforms else 1
    for plat, count in sorted(platforms.items(), key=lambda x: -x[1]):
        bar = "█" * int(count / max_count * 30)
        print(f"  {plat:12} {count:4}  {C.G}{bar}{C.NC}")
    
    if cf_categories:
        print(f"\n{C.B}Codeforces Categories:{C.NC}")
        for cat, count in sorted(cf_categories.items(), key=lambda x: -x[1]):
            print(f"  {cat:12} {count:4}")
    
    if cses_topics:
        print(f"\n{C.B}CSES Topics:{C.NC}")
        for topic, count in sorted(cses_topics.items(), key=lambda x: -x[1]):
            print(f"  {topic:12} {count:4}")
    
    if usaco_divs:
        print(f"\n{C.B}USACO Divisions:{C.NC}")
        for div, count in sorted(usaco_divs.items(), key=lambda x: -x[1]):
            print(f"  {div:12} {count:4}")
    
    cache = get_cache()
    print(f"\n{C.D}Cache: {len(cache.contests)} CF contests, {len(cache.gyms)} gyms{C.NC}")


# ============================================================================
#  CLEAN COMMAND - Remove empty directories
# ============================================================================

def clean_empty_dirs():
    """Remove empty directories."""
    print("Cleaning empty directories...\n")
    removed = 0
    
    for dirpath, dirnames, filenames in os.walk(str(SOLVED_DIR), topdown=False):
        path = Path(dirpath)
        if path.name == '.cph':
            continue
        
        contents = [p for p in path.iterdir() if p.name != '.cph']
        if not contents:
            try:
                cph_dir = path / '.cph'
                if cph_dir.exists():
                    shutil.rmtree(cph_dir)
                path.rmdir()
                print(f"  Removed: {path.relative_to(ROOT_DIR)}")
                removed += 1
            except:
                pass
    
    print(f"\nRemoved {removed} empty directories")


# ============================================================================
#  FETCH COMMAND - Update API cache
# ============================================================================

def fetch_data():
    """Fetch/update data from online judge APIs."""
    cache = get_cache()
    cache.update()


# ============================================================================
#  MAIN
# ============================================================================

def main():
    parser = argparse.ArgumentParser(
        description="Competitive Programming Helper - Dynamic Organization",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  ./cph.py move              # Move files to platform folders
  ./cph.py sort              # Sort all platforms
  ./cph.py sort --platform cf # Sort only CF
  ./cph.py stats             # Show statistics
  ./cph.py fetch             # Update API cache
  ./cph.py clean             # Remove empty directories
"""
    )
    
    subparsers = parser.add_subparsers(dest='command', help='Commands')
    
    move_parser = subparsers.add_parser('move', help='Move files to platform folders')
    move_parser.add_argument('--dry-run', '-n', action='store_true', help='Preview only')
    
    sort_parser = subparsers.add_parser('sort', help='Sort files into categories')
    sort_parser.add_argument('--dry-run', '-n', action='store_true', help='Preview only')
    sort_parser.add_argument('--platform', '-p', default='all', 
                            choices=['all', 'cf', 'cses', 'usaco'],
                            help='Platform to sort')
    
    subparsers.add_parser('stats', help='Show statistics')
    subparsers.add_parser('clean', help='Remove empty directories')
    subparsers.add_parser('fetch', help='Update API cache')
    
    args = parser.parse_args()
    
    if not args.command:
        parser.print_help()
        return
    
    if args.command == 'move':
        move_files(args.dry_run)
    elif args.command == 'sort':
        sort_files(args.platform, args.dry_run)
    elif args.command == 'stats':
        show_stats()
    elif args.command == 'clean':
        clean_empty_dirs()
    elif args.command == 'fetch':
        fetch_data()


if __name__ == '__main__':
    main()
