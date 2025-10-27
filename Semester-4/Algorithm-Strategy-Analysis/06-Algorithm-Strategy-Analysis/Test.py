listMorse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
             ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
             ".--", "-..-", "-.--", "--.."]

morseToChar = {
    ".-"  : "A", "-..." : "B", "-.-." : "C", "-.."  : "D", "."   : "E",
    "..-." : "F", "--."  : "G", "...." : "H", ".."   : "I", ".---" : "J",
    "-.-"  : "K", ".-.." : "L", "--"   : "M", "-."   : "N", "---"  : "O",
    ".--." : "P", "--.-" : "Q", ".-."  : "R", "..."  : "S", "-"    : "T",
    "..-"  : "U", "...-" : "V", ".--"  : "W", "-..-" : "X", "-.--" : "Y",
    "--.." : "Z"
}

# Menyimpan hasil kombinasi valid
def countMorseValid(index, string, current_path, current_letters):
    if index == len(string):
        # Cetak jalur yang valid dalam kode Morse dengan '/' sebagai pemisah
        print("/".join(current_path), "=>", "".join(current_letters))
        return 1
    
    total = 0
    for length in range(1, 5):
        if index + length <= len(string):
            subString = string[index:index+length]  
            if subString in listMorse:  
                total += countMorseValid(index + length, string, 
                                         current_path + [subString], 
                                         current_letters + [morseToChar[subString]])
    return total

string = ".-..-"
total_valid = countMorseValid(0, string, [], [])
print("Total kombinasi valid:", total_valid)
