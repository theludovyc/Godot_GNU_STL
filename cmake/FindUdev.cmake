set(UDEV_ROOT_DIR
    "${UDEV_ROOT_DIR}"
	CACHE
	PATH
    "Directory to search for udev")

find_library(UDEV_LIBRARY
	NAMES
	udev
	HINTS
	"${UDEV_ROOT_DIR}"
	PATH_SUFFIXES
	lib
	)

get_filename_component(_libdir "${UDEV_LIBRARY}" PATH)

find_path(UDEV_INCLUDE_DIR
	NAMES
	libudev.h
	HINTS
	"${_libdir}"
	"${_libdir}/.."
	"${UDEV_ROOT_DIR}"
	PATH_SUFFIXES
	include
	)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Udev
	DEFAULT_MSG
	UDEV_LIBRARY
	UDEV_INCLUDE_DIR
	)

if(UDEV_FOUND)
	list(APPEND UDEV_LIBRARIES ${UDEV_LIBRARY})
	list(APPEND UDEV_INCLUDE_DIRS ${UDEV_INCLUDE_DIR})
	mark_as_advanced(UDEV_ROOT_DIR)
endif()

mark_as_advanced(UDEV_INCLUDE_DIR
	UDEV_LIBRARY)
