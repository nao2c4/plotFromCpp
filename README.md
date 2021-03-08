# C++からPythonコード呼び出し

## 概要

適当にPythonのMatplotlibを使ってプロットに限定したプログラムを書き，C++側で制御した．

## Files

| Name | Content |
| --- | --- |
| `a.cpp` | C++のコード |
| `plot.py ` | Pythonのコード |

## やり方概要

<strong>C++の`_popen`関数を使って他のプログラムを動かすことが可能．</strong>

> Linuxでは`popen`関数という名前らしい？
> Windowsは機能が少し違う`_popen`関数というものらしい？
> (要検討)

### `_popen`関数

```c++
FILE *_popen(
    const char *command,
    const char *mode
);
```

`FILE`ポインタは`fprintf`関数で使ういつものファイルポインタ．

```c++
// b.pyをバックグラウンドで起動
fp = _popen("b.py", "w");
// b.pyにTohokuを入力した扱い
// \nが必要
fprintf(fp, "Tohoku\n");
```

### `_pclose`関数

```c++
int _pclose(
    FILE *stream
);
```

ファイルポインタは開くと閉じる必要があり．

```c++
// b.pyをバックグラウンドで起動
fp = _popen("b.py", "w");
/* 色々な処理 */
// ファイルポインタを閉じる
_pclose(fp);
```

### その他

環境によっては`fflush(fp)`をする必要あるかも．

## References

- [\_popen, \_wpopen | Microsoft Docs](https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/reference/popen-wpopen)
- [\_pclose | Microsoft Docs](https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/reference/pclose)
- [fflush - cppreference.com](https://en.cppreference.com/w/c/io/fflush) &larr; Cバージョン
- [std::fflush - cppreference.com](https://en.cppreference.com/w/cpp/io/c/fflush) &larr; C++バージョン

## C++おすすめ参考書 (もしC++を学びたい or 深く知りたいなら)

- [江添亮のC++入門](https://ezoeryou.github.io/cpp-intro/)
- [C++11の文法と機能](https://ezoeryou.github.io/cpp-book/C++11-Syntax-and-Feature.xhtml)
