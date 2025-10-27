def push_rank(n, start_stars, target_stars, opponent_stars):
    # Impossible scenarios
    if start_stars == target_stars:
        return 0
    if start_stars < 1 or target_stars < 1:
        return -1
    
    # Track matches per opponent
    match_counts = [0] * n
    
    # Tracking game state
    current_stars = start_stars
    total_matches = 0
    
    # Sort opponents for strategic selection
    sorted_opponents = sorted(enumerate(opponent_stars), key=lambda x: x[1])
    
    def can_play_opponent(opponent_idx, max_matches):
        # Check if this opponent can be played based on matchmaking rules
        return match_counts[opponent_idx] < max_matches
    
    while current_stars != target_stars:
        # Find maximum matches played
        max_matches = max(match_counts)
        
        # Find a playable opponent
        best_opponent = None
        for idx, (orig_idx, stars) in enumerate(sorted_opponents):
            # Ensure we can play this opponent
            if not can_play_opponent(idx, max_matches + 1):
                continue
            
            # Prioritize matches based on star difference
            if (stars < current_stars and best_opponent is None) or \
               (best_opponent is not None and 
                stars < sorted_opponents[best_opponent][1]):
                best_opponent = idx
        
        # No valid opponent found
        if best_opponent is None:
            return -1
        
        # Play the match
        orig_idx, opponent_stars = sorted_opponents[best_opponent]
        match_counts[best_opponent] += 1
        total_matches += 1
        
        # Update star count
        if opponent_stars < current_stars:
            current_stars += 1
        else:
            current_stars -= 1
        
        # Prevent infinite loop
        if total_matches > n * n * 2:
            return -1
        
        # Additional safety checks
        if current_stars < 1:
            return -1
    
    return total_matches

# Test cases with detailed debugging
test_cases = [
    (6, 1, 11, [5, 3, 1, 4, 2, 9]),  # Example 1
    (7, 1, 10, [3, 1, 9, 2, 5, 20, 8])  # Example 2
]

for i, (n, start, target, opponents) in enumerate(test_cases, 1):
    result = push_rank(n, start, target, opponents)
    print(f"Test Case {i}:")
    print(f"  Opponents: {opponents}")
    print(f"  Start Stars: {start}")
    print(f"  Target Stars: {target}")
    print(f"  Result: {result}")
    print()