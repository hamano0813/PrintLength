import setuptools

with open("README.md", "r", encoding='utf-8') as fh:
    long_description = fh.read()

setuptools.setup(
    name="PrintLength",
    version="1.0",
    author="Hamano0813",
    author_email="hamano0813@gmail.com",
    license="MIT",
    description="calculate the length of CJK characters or Integers and Floats",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/hamano0813/PrintLength",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    data_files=[("", ["LICENSE"]), ("", ["README.md"]), ("", ["PrintLength.pyi"])],
    ext_modules=[setuptools.Extension("PrintLength", ["PrintLength.c"])],
    python_requires=">=3.6",
)
