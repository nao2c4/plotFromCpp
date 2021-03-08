import numpy as np
import matplotlib
import matplotlib.pyplot as plt


if __name__ == '__main__':
    fig = plt.figure()
    ax = fig.add_subplot()
    path = input()
    while len(path) > 3:
        data = np.loadtxt(path)
        ax.plot(data)
        # fig.show()
        plt.pause(0.001)
        path = input()
        ax.clear()
