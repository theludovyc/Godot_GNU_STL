# Generate AES256 script encryption key
import os
import sys


def generate_script_encryption_key():
    txt = "0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0"

    if "SCRIPT_AES256_ENCRYPTION_KEY" in os.environ:
        key = os.environ["SCRIPT_AES256_ENCRYPTION_KEY"]
        ec_valid = True
        if len(key) != 64:
            ec_valid = False
        else:
            txt = ""
            for i in range(len(key) >> 1):
                if i > 0:
                    txt += ","
                txts = "0x" + key[i * 2: i * 2 + 2]
                try:
                    int(txts, 16)
                except Exception:
                    ec_valid = False
                txt += txts
        if not ec_valid:
            print("Error: Invalid AES256 encryption key, not 64 hexadecimal characters: '" + key + "'.")
            print(
                "Unset 'SCRIPT_AES256_ENCRYPTION_KEY' in your environment "
                "or make sure that it contains exactly 64 hexadecimal characters."
            )
            sys.exit(1)

    # NOTE: It is safe to generate this file here, since this is still executed serially
    with open("core/script_encryption_key.gen.cpp", "w") as f:
        f.write('#include "core/config/project_settings.h"\nuint8_t script_encryption_key[32]={' + txt + "};\n")

if __name__ == "__main__":
    generate_script_encryption_key()
