import yaml
from conans import ConanFile, tools, CMake
from iressconanutils.tools import msvc_build_command, group_output

class ToyRobotConan(ConanFile):
    name = "ToyRobot"
    version = "1.0"
    description = "TODO: description about component"
    license = "???"
    url = "https://bitbucket.devel.iress.com.au/scm/~stanley.klemme/robot.git"
    yamlrequires = yaml.load(open('IressProjectRequires.yml', 'r'))
    requires = tuple(yamlrequires['RequiredByConsumers'])
    exports = "IressProjectRequires.yml"
    exports_sources = (
        "src/*"
    )
    generators = "visual_studio", "cmake", "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    cmake_options = { "BUILD_UNIT_TEST" : "ON" }

    @group_output
    def build(self):
        print("Generating project...")
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure( defs=self.cmake_options )
        print("Building project...")
        build_command = msvc_build_command(
            self.settings,
            "toy_robot.vcxproj",
            upgrade_project=False
        )
        self.output.info("Build command: %s" % build_command)
        self.run(build_command)

    def package(self):
        output_folder = 'bin/' + str(self.settings.build_type).lower() + ('x64' if '64' in str(self.settings.arch) else '')

        self.copy("*.h", src="src", dst="include")
        self.copy("*.hpp", src="src", dst="include")
        self.copy("*.lib", src=output_folder, dst="lib", keep_path=False)
        self.copy("*.dll", src=output_folder, dst="bin", keep_path=False, excludes=[])
        self.copy("*.exe", src=output_folder, dst="bin", keep_path=False, excludes=[])
        self.copy("*.pdb", src=output_folder, dst="bin", keep_path=False, excludes=['vc*.pdb'])

    def package_info(self):
        self.cpp_info.includedirs = ['include'] # Ordered list of include paths
        self.cpp_info.libs = ['LIB_ROBOT.lib']  # The libs to link against
        self.cpp_info.libdirs = ['lib']         # Directories where libraries can be found
        self.cpp_info.bindirs = ['bin']         # Directories where executables and shared libs can be found   
