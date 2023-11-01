# PrintLength

## 项目描述

计算文字的长度，中文算2个字符，英文算1个字符，数值包含千位分隔符，小数点后保留2位小数，不足2位补0

## 构建方法

双击`build.bat`生成pyd文件

## 使用方法

```python
import PrintLength

print(PrintLength.len("1234567890"), 13)
print(PrintLength.len("1234567890.123"), 16)
print(PrintLength.len("1234567890.1"), 15)
print(PrintLength.len("这是1个例子"), 11)
print(PrintLength.len("这是一个例子"), 12)
print(PrintLength.lens(['例子1', '例子二', '仅作为测试']), 10)
```
