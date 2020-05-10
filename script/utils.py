"""Functions used to generate source files during build time

All such functions are invoked in a subprocess on Windows to prevent build flakiness.
"""
def escape_string(s):
    def charcode_to_c_escapes(c):
        rev_result = []
        while c >= 256:
            c, low = (c // 256, c % 256)
            rev_result.append("\\%03o" % low)
        rev_result.append("\\%03o" % c)
        return "".join(reversed(rev_result))

    result = ""
    if isinstance(s, str):
        s = s.encode("utf-8")
    for c in s:
        if not (32 <= c < 127) or c in (ord("\\"), ord('"')):
            result += charcode_to_c_escapes(c)
        else:
            result += chr(c)
    return result

