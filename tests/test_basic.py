import dztimer
from time import sleep

def test_dztimer():
    timer = dztimer.Timing()
    timer.start("Total")
    timer[0].start("One Scan Cost")
    sleep(0.00005)
    timer[0].stop()
    
    for i in range(3):
        timer[1].start("Second Scan Cost")
        sleep(0.3 + i * 0.1)
        timer[1].stop()
    print(f"The timing last record: {timer[1].lastSeconds():.2f} s")

    for i in range(10):
        timer[2].start("Third Scan Cost")
        sleep(0.1)
        timer[2].stop()
    
    timer.print(random_colors=True, bold=True, precision=4)

if __name__ == "__main__":
    test_dztimer()