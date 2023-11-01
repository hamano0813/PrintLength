import setuptools

setuptools.setup(
    name="PrintLength",
    version="1.0",
    author="Hamano0813",
    author_email="hamano0813@gmail.com",
    license="MIT",
    description="calculate the length of CJK characters or Integers and Floats",
    url="https://github.com/hamano0813/PrintLength",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    ext_modules=[setuptools.Extension("PrintLength", ["PrintLength.c"])],
)
