#!/usr/bin/env python

# Copyright 2017 Udey Rishi
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import shutil
import os
from subprocess import call
import sys

PROJECT_NAME = os.path.dirname(os.path.realpath(__file__))

if __name__ == '__main__':
    parser = argparse.ArgumentParser('Build {0} and {0}_tests'.format(PROJECT_NAME))
    parser.add_argument('-d', '--debug', help='Build the debug version', action='store_true')
    parser.add_argument('-r', '--rebuild', help='Clean before building', action='store_true')
    args = parser.parse_args()

    if args.rebuild:
        try:
            shutil.rmtree('out')
        except OSError:
            pass

    build_type = 'debug' if args.debug else 'release'
    out_dir = os.path.join('out', build_type)
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)
    os.chdir(out_dir)
    cmake_args = ['cmake', '-DCMAKE_BUILD_TYPE=' + build_type]
    if 'CPP_COMPILER' in os.environ:
        cmake_args.append('-DCMAKE_CXX_COMPILER=' + os.environ['CPP_COMPILER'])
    if 'C_COMPILER' in os.environ:
        cmake_args.append('-DCMAKE_C_COMPILER=' + os.environ['C_COMPILER'])
    cmake_args.append('../..')
    code = call(cmake_args)
    if code:
        exit(code)
    code = call(['make'])
    if code:
        exit(code)
