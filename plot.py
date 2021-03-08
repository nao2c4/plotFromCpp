import numpy as np
import matplotlib
import matplotlib.pyplot as plt


if __name__ == '__main__':
    # Figure作成
    fig = plt.figure()
    # 軸作成
    ax = fig.add_subplot()
    # 入力待ち (1回目)
    path = input()
    # ループ
    # 普通ファイル名は4文字以上が多いため適当に条件を設定
    while len(path) > 3:
        # ファイル読み込み
        data = np.loadtxt(path)
        # プロット
        ax.plot(data)
        # 表示
        # こうすると途中でグラフを表示可能らしい
        plt.pause(0.001)
        # 入力待ち
        path = input()
        # 次のプロットのために表示消す
        ax.clear()
