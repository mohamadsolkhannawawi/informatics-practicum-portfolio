# Morse code reverse mapping for alphabet 
reverse_code = [
    '.−', '−...', '−.−.', '−..', '.', '..−.', '−−.', 
    '....', '..', '.−−−', '−.−', '.−..', '−−', '−.', 
    '−−−', '.−−.', '−−.−', '.−.', '...', '−', '..−', 
    '...−', '.−−', '−..−', '−.−−', '−−..'
]

def decode_morse_possibilities(s):
    def count_possibilities(current_string):
        # Base case: if string is empty, return 1
        if len(current_string) == 0:
            return 1
        
        total_possibilities = 0
        
        # Check for 1-4 character morse code possibilities
        for length in range(1, min(5, len(current_string) + 1)):
            # Extract potential morse code
            potential_code = current_string[:length]
            
            # Check if the potential code is in the reverse_code list
            if potential_code in reverse_code:
                # If valid, recursively count possibilities for the remaining string
                total_possibilities += count_possibilities(current_string[length:])
        
        return total_possibilities

# Process input and print output
while True:
    try:
        s = input().strip()
        print(decode_morse_possibilities(s))
    except EOFError:
        break


morse_dict = {
    ".-": "A", "-...": "B", "-.-.": "C", "-..": "D", ".": "E", 
    "..-.": "F", "--.": "G", "....": "H", "..": "I", ".---": "J", 
    "-.-": "K", ".-..": "L", "--": "M", "-.": "N", "---": "O", 
    ".--.": "P", "--.-": "Q", ".-.": "R", "...": "S", "-": "T", 
    "..-": "U", "...-": "V", ".--": "W", "-..-": "X", "-.--": "Y", 
    "--..": "Z"
}

def count_morse_possibilities(s):
    def dp(index):
        if index == len(s):
            return 1
        
        total = 0
        for length in range(1, 5):
            if index + length <= len(s):
                substr = s[index:index+length]
                if substr in morse_dict:
                    total += dp(index + length)
        
        return total

    return dp(0)

# Read input
s = input().strip()
# Print output
print(count_morse_possibilities(s))
