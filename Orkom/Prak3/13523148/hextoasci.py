def hex_to_ascii(hex_str):
    try:
        # Decode the hex string to ASCII
        ascii_str = bytes.fromhex(hex_str).decode('ascii')
        return ascii_str
    except ValueError:
        return "Invalid hex"

def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    hex_str_arr = [
        "447b336d6f6b724f",
        "726f772074276e6f",
        "6c6c2749202c7972",
        "79736165206f6720",
        "3962646537315f2e",
        "6332623866653531",
        "7d6366"
    ]

    for hex_str in hex_str_arr:
        ascii_str = hex_to_ascii(hex_str)
        if ascii_str != "Invalid hex":
            reversed_str = reverse_string(ascii_str)
            print("", reversed_str)
        else:
            print("Invalid hex string provided.")
