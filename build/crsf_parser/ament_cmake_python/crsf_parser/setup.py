from setuptools import find_packages
from setuptools import setup

setup(
    name='crsf_parser',
    version='0.1.0',
    packages=find_packages(
        include=('crsf_parser', 'crsf_parser.*')),
)
