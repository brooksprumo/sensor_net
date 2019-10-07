project(
    'sensor_net',
    'cpp',
    version: '1.0.0',
    license: 'MIT',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3',
    ],
)

thread_dep = dependency('threads')
catch2_proj = subproject('catch2')
catch2_dep = catch2_proj.get_variable('catch2_dep')
boost_dep = dependency('boost')

sensor_net_lib = library(
    'sensor_net_lib',
    sources: [
      'sensor_net'/'Buffer.cpp',
      'sensor_net'/'Reporter.cpp',
      'sensor_net'/'Sampler.cpp',
      'sensor_net'/'Sensor.cpp',
      'sensor_net'/'SensorState.cpp',
    ],
    dependencies: boost_dep,
)

sensor_net_exe = executable(
    'sensor_net',
    sources: [
      'sensor_net'/'main.cpp',
    ],
    dependencies: thread_dep,
    link_with: sensor_net_lib,
)

sensor_net_test = executable(
    'test_sensor_net',
    sources: [
        'test'/'test_Buffer.cpp',
        'test'/'test_Reporter.cpp',
        'test'/'test_Sensor.cpp',
        'test'/'test_main.cpp',
    ],
    link_with: sensor_net_lib,
    dependencies: catch2_dep,
)

test(
    'tests for sensor_net library',
    sensor_net_test,
)
