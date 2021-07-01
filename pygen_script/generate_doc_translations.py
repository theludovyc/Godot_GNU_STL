from editor_builders import make_translations_header

if __name__ == "__main__":
    make_translations_header("editor/doc_translations.gen.h", "doc/translations", "doc")
