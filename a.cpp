#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

// ユニークポインタのエイリアス
using file_ptr_t = std::unique_ptr<FILE, decltype(&fclose)>;

// Pythonにファイルを送るためのクラス
class Pipe {
 private:
  file_ptr_t _file_ptr;

 public:
  Pipe(const char* program_path) : _file_ptr(_popen(program_path, "w"), _pclose) {}

	// コード送信
  void command(const char* cmd) {
    std::fprintf(_file_ptr.get(), cmd);
    std::fflush(_file_ptr.get());
  }
};

// Main関数
// 1秒ことに数字を保存
// Pythonスクリプトにプロットするように指示
int main() {
	// 保存ファイルパス
  const char* data_file = "data.txt";
	// ファイルを送るための初期設定
  Pipe pipe("plot.py");
	// 保存する数字たち
  std::vector<double> arr{0, 1, 2, 2.8, 4.5, 5, 6.8, 7, 7, 7.5, 9.};
	// ループ
  for (const auto x : arr) {
		// ファイルに追記
    auto fout = std::ofstream(data_file, std::ios_base::app);
    fout << x << "\n";
    fout.close();
		// Pythonのコードに送る
    pipe.command((data_file + std::string("\n")).c_str());
		// 1秒待つ
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
	// Pythonに終了するように指示
  pipe.command("q");

  return 0;
}
