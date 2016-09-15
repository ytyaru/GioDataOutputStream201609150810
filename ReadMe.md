# このソフトウェアについて #

GioDataOutputStream201609150810は私個人が学習目的で作成したソフトウェアです。

Gio::DataOutputStreamをもちいてUTF-8ファイルを書き込む。

# 開発環境 #

* Windows XP Pro SP3 32bit
* VC++ 2010 Express
    * C++/Win32

## ライブラリ ##

* [Gtkmm 2.22](http://ftp.gnome.org/pub/GNOME/binaries/win32/gtkmm/2.22/gtkmm-win32-devel-2.22.0-2.exe)
    * GTKmm 2.4
        * GTK+ 2.22.0
    * glibmm 2.4
        * glib 2.0
    * giomm 2.4
        * gio 2.0

# イメージ #

![Window](https://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160912/20160912231342.png)

# 説明 #

## 問題なし ##

[前回](https://github.com/ytyaru/GlibUstringFile201609141732)と違い、C++を使えた。
[前々回](https://github.com/ytyaru/GtkOnFstream201609130731)と違い、GTK::Window(マルチスレッド)でも実行エラーなく動作する。

GTKmmでファイル出力するときは`Gio::DataOutputStream`を使うのが好ましいのかもしれない。

## ファイル形式 ##

* UTF-8
* BOM無し
* 改行コード:LF

上記のようになる。

WindowsからみるとBOM付、CR+LFのほうが都合がいい。
でも、設定する関数が見当たらない。
おそらく自前で挿入する必要がある。

# ライセンス #

このソフトウェアはCC0ライセンスです。

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)
