import os
def update_version(module_version_string=""):

    build_name = "custom_build"
    if os.getenv("BUILD_NAME") != None:
        build_name = os.getenv("BUILD_NAME")
        print("Using custom build name: " + build_name)

    import version

    # NOTE: It is safe to generate this file here, since this is still executed serially
    f = open("core/version_generated.gen.h", "w")
    f.write("#define VERSION_SHORT_NAME \"" + str(version.short_name) + "\"\n")
    f.write("#define VERSION_NAME \"" + str(version.name) + "\"\n")
    f.write("#define VERSION_MAJOR " + str(version.major) + "\n")
    f.write("#define VERSION_MINOR " + str(version.minor) + "\n")
    f.write("#define VERSION_PATCH " + str(version.patch) + "\n")
    f.write("#define VERSION_STATUS \"" + str(version.status) + "\"\n")
    f.write("#define VERSION_BUILD \"" + str(build_name) + "\"\n")
    f.write("#define VERSION_MODULE_CONFIG \"" + str(version.module_config) + module_version_string + "\"\n")
    f.write("#define VERSION_YEAR " + str(version.year) + "\n")
    f.write("#define VERSION_WEBSITE \"" + str(version.website) + "\"\n")
    f.close()

    # NOTE: It is safe to generate this file here, since this is still executed serially
    fhash = open("core/version_hash.gen.h", "w")
    githash = ""
    gitfolder = ".git"

    if os.path.isfile(".git"):
        module_folder = open(".git", "r").readline().strip()
        if module_folder.startswith("gitdir: "):
            gitfolder = module_folder[8:]

    if os.path.isfile(os.path.join(gitfolder, "HEAD")):
        head = open(os.path.join(gitfolder, "HEAD"), "r").readline().strip()
        if head.startswith("ref: "):
            head = os.path.join(gitfolder, head[5:])
            if os.path.isfile(head):
                githash = open(head, "r").readline().strip()
        else:
            githash = head

    fhash.write("#define VERSION_HASH \"" + githash + "\"")
    fhash.close()

if __name__ == "__main__":
    update_version()