dztimer
---

A beautiful timer from ufomap by Daniel Duberg, nanobind by Qingwen Zhang.

Running on macOS, Windows and Linux.

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