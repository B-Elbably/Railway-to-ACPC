import itertools

def solve_brute_force(n, k):
    nums = list(range(1, n + 1)) * 2
    for p in set(itertools.permutations(nums)):
        if simulate(list(p)) == k:
            return "YES", p
    return "NO", None

def simulate(cards):
    n = len(cards) // 2
    flipped_indices = [False] * (2 * n)
    known_pos = {} # number: [indices]
    discarded = [False] * (2 * n)
    turns = 0
    
    while sum(discarded) < 2 * n:
        turns += 1
        
        # 1. Check if two known cards have the same number
        pair_to_flip = None
        for num, indices in known_pos.items():
            if len(indices) == 2:
                pair_to_flip = indices
                break
        
        if pair_to_flip:
            c1, c2 = pair_to_flip
            discarded[c1] = discarded[c2] = True
            del known_pos[cards[c1]]
            continue

        # 2. Flip the first card never flipped as a first card
        idx1 = -1
        for i in range(2 * n):
            if not flipped_indices[i] and not discarded[i]:
                idx1 = i
                break
        
        val1 = cards[idx1]
        flipped_indices[idx1] = True
        
        # 3. Check if val1 was previously known
        if val1 in known_pos and idx1 not in known_pos[val1]:
            idx2 = known_pos[val1][0]
            discarded[idx1] = discarded[idx2] = True
            del known_pos[val1]
        else:
            if val1 not in known_pos:
                known_pos[val1] = []
            if idx1 not in known_pos[val1]:
                known_pos[val1].append(idx1)
            
            # 4. Flip the first card never flipped so far as the second card
            idx2 = -1
            for i in range(2 * n):
                if not flipped_indices[i] and not discarded[i]:
                    idx2 = i
                    break
            
            val2 = cards[idx2]
            flipped_indices[idx2] = True
            
            if val1 == val2:
                discarded[idx1] = discarded[idx2] = True
                del known_pos[val1]
            else:
                if val2 not in known_pos:
                    known_pos[val2] = []
                known_pos[val2].append(idx2)
                
    return turns

# n = 4
# for k in range(n, n * 2) :
#     print(k, solve_brute_force(n, k)[1])
    
solve_brute_force(6, 10)

# 1 -> 1
# 2 -> 3
# 3 -> 5
# 4 -> 7
# 5 -> 9