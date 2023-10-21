import dztimer
from time import sleep

def test_dztimer():
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

if __name__ == "__main__":
    test_dztimer()