dztimer
---

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