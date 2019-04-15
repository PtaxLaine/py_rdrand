#!/usr/bin/env python3

from setuptools import setup
from setuptools.extension import Extension
import setuptools.command.build_py
import subprocess
import os
import locale

try:
    from Cython.Distutils import build_ext
    with_cython = True
except ImportError:
    from distutils.command.build_ext import build_ext
    with_cython = False

extensions = [Extension("rdrand", ["rdrand.pyx", "_rdrand.cpp"] if with_cython else ["rdrand.cpp", "_rdrand.cpp"],
        include_dirs = ['.'],
        language = 'c++',
        extra_compile_args=['-mrdrnd', '-lstdc++'] if os.name != 'nt' else []
    )]

setup(
    name = "rdrand",
    version="0.1.0",
    author="Andrei V",
    author_email="anderi@ptaxa.net",
    description="RDRAND",
    license="MIT",
    keywords="",
    url="",
    ext_modules = extensions,
    cmdclass={'build_ext': build_ext},
)
