dztimer
---
<!-- <a href="https://github.com/KTH-RPL/dztimer"><img src="https://img.shields.io/github/v/release/KTH-RPL/dztimer?label=version" /> <a href="https://github.com/KTH-RPL/dztimer/blob/master/LICENSE"><img src="https://img.shields.io/github/license/KTH-RPL/dztimer" />  -->
<img src="https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black" />
<img src="https://img.shields.io/badge/Windows-0078D6?st&logo=windows&logoColor=white" />
<img src="https://img.shields.io/badge/mac%20os-000000?&logo=apple&logoColor=white" />
<!-- <img src="https://img.shields.io/pypi/pyversions/dztimer.svg" /></a> -->

A beautiful timer from ufomap by [Daniel Duberg](https://www.kth.se/profile/dduberg), nanobind by [Qingwen Zhang](https://kin-zhang.github.io/).

Running on macOS, Windows and Linux.

TestDemo:
```bash
pip install --index-url https://test.pypi.org/simple/ --extra-index-url https://pypi.org/simple/ dztimer
```

Quick Demo:
```python
import dztimer
from time import sleep

timer = dztimer.Timing()
timer.start("Total")
timer[0].start("One Scan Cost")
for i in range(5):
    sleep(0.05 + i * 0.01)
timer[0].stop()

for i in range(5):
    timer[1].start("Second Scan Cost")
    sleep(0.08 + i * 0.01)
    timer[1].stop()
timer.print(random_colors=True, bold=True)
```

![image](https://github.com/Kin-Zhang/Kin-Zhang/assets/35365764/ca5ab0e7-e79d-47e0-bf77-9f837397f72a)

<!-- Tutorial on nanobind and pypi release in [Chinese blog](TODO) -->



### Issue I met when write this package
1. multiple platform support, especially for windows, there is an error: error C2668: 'fpclassify': ambiguous call to overloaded function,[https://stackoverflow.com/questions/61646166/how-to-resolve-fpclassify-ambiguous-call-to-overloaded-function](https://stackoverflow.com/questions/61646166/how-to-resolve-fpclassify-ambiguous-call-to-overloaded-function). It's turn out if you want to `std::isnan()` in windows, you need to include `<cmath>` and `std::isnan(static_cast<double> (you_value))`.
2. If you use `std::array` except linux, you need to include `#include <array>` and `std::array<int, 2> my_array;` instead of `std::array my_array;`
3. 