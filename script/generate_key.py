# Generate AES256 script encryption key
import os
txt = "0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0"
if ("SCRIPT_AES256_ENCRYPTION_KEY" in os.environ):
    e = os.environ["SCRIPT_AES256_ENCRYPTION_KEY"]
    txt = ""
    ec_valid = True
    if (len(e) != 64):
        ec_valid = False
    else:

        for i in range(len(e) >> 1):
            if (i > 0):
                txt += ","
            txts = "0x" + e[i * 2:i * 2 + 2]
            try:
                int(txts, 16)
            except:
                ec_valid = False
            txt += txts
    if (not ec_valid):
        txt = "0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0"
        print("Invalid AES256 encryption key, not 64 bits hex: " + e)

# NOTE: It is safe to generate this file here, since this is still executed serially
with open("script_encryption_key.gen.cpp", "w") as f:
    f.write("#include \"core/project_settings.h\"\nuint8_t script_encryption_key[32]={" + txt + "};\n")