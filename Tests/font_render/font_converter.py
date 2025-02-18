# se debe emplear un fichero como el de 'font6x6.txt', separando cada
# carácter con un símbolo '-' en una línea nueva.
# recomendable usarlo con un cauce:
#   python3 font_converter.py < font6x6.txt > result.txt
# y luego copiarlo a la definición de la fuente (como en font.h)

def binary_string_to_hex(input_string):
    # ensure the input string is valid binary
    if not all(bit in '01' for bit in input_string):
        raise ValueError("Input string must be a binary string (only 0s and 1s).")

    # split the string into groups of 4 bits
    n = 4
    binary_groups = [input_string[i:i+n] for i in range(0, len(input_string), n)]
    
    # convert each group to hexadecimal
    hex_value = ''.join(format(int(group, 2), 'X') for group in binary_groups)
    
    # return the hexadecimal value in the format "0xxx"
    return f"0x{hex_value}"

if __name__ == "__main__":
    try:
        print("{", end="")
        while True:
            line = input()
            if (line != "-"):
                print(binary_string_to_hex(line[::-1]), end="")
                print(", ", end="")
            else:
                print("},")
                print("{", end="")
    except EOFError:
        pass

# gracias chatGPT!
