"""Functions used to generate source files during build time

All such functions are invoked in a subprocess on Windows to prevent build flakiness.
"""

from pygen_script.platform_methods import subprocess_main


def generate_modules_enabled(target, source, env):
    with open(target[0].path, "w") as f:
        for module in env.module_list:
            f.write("#define %s\n" % ("MODULE_" + module.upper() + "_ENABLED"))


def generate_modules_tests(target, source, env):
    import os
    import glob

    with open(target[0].path, "w") as f:
        for name, path in env.module_list.items():
            headers = glob.glob(os.path.join(path, "tests", "*.h"))
            for h in headers:
                f.write('#include "%s"\n' % (os.path.normpath(h)))


if __name__ == "__main__":
    subprocess_main(globals())
