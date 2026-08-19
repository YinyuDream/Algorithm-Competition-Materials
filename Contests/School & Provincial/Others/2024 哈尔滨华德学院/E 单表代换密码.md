# 单表代换密码

**题目背景**

相信大家都知道凯撒密码吧。

单表代换密码和凯撒密码类似，都是一种加密算法。

单表代换密码是根据密码表代换进行加密解密的。

单表代换密码的密码表分为两部分，明文字母表和密文字母表。

本题的明文字母表固定为小写的 $26$ 位英文字母及如下。(在本题内，如空格以及标点符号等特殊字符不进行加密处理。)

a b c d e f g h i j k l m n o p q r s t u v w x y z

单表代换密码的核心部分为密文字母表的生成。

本题的密文字母表固定为大写的 $26$ 位英文字母。具体的密文字母表的生成规则如下：

密文字母表的生成需要一个秘钥短语。

例如 Harbin Huade University!

第一步，去掉特殊字符并且全部字母转为大写。

HARBINHUADEUNIVERSITY

第二步对于字符串内重复的字符进行去重，只保留第一次出现的时候。

HARBINUDEVSTY

第三步把26个英文字母中没有在秘钥短语种出现过得，依次接在末尾。

HARBINUDEVSTYCFGJKLMOPQWXZ

这样就得出了密文字母表。

然后把明文字母表与密文字母表对应，就是加密解密的规则了。

例如

| a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| H | A | R | B | I | N | U | D | E | V | S | T | Y | C | F | G | J | K | L | M | O | P | Q | W | X | Z |

利用这样的对应表，就可以对小写字母为主体组成的字符串进行加密了。

在加密的过程中，就是把小写字母替换为对应的大写字母，特殊字符保持原装不进行处理。

例如

i want all killed icpc world final！

加密之后为
E QHCM HTT SETTIB ERGR QFKTB NECHT！

**题目描述**

现在请你根据以上的单表代换密码的描述，写一个单表代换密码加密解密工具。

工具需要实现的功能如下

工具开始运行时输入一个秘钥字符串 $Secretkey$ **。**
**（注意，字符串 $Secretkey$ 内可能包含空格等特殊字符，处理方式如上述描述** **）**

然后输入多组指令，指令分为两种情况。

第一种情况，包含**两行字符串**。

第一行字符串为 $encryption$ 或 $decryption$ ，代表加密还是解密。

第二行字符串为需要加密的明文或者需要解密的密文。
（需要加密的明文中保证不会出现大写字母，需要解密的密文中保证不会出现小写字母）。

第一种情况需要根据指令加密或解密字符串，然后输出结果，结果独占一行。

第二种情况，只会出现在最后一组指令，只包含一行，一个字符串 $END$ ，代表程序结束运行指令。

第二种情况需要在接收到程序结束运行指令后，输出一个字符串 Thanks for using goodbye! 后在结束程序运行。

## 输入描述:

第一行一个 字符串 $Secretkey$，$Secretkey$ 可能包含特殊字符，但是保证只有一行。

$1\leq len\left( Secretkey \right)\leq 10^{5}$

接下来为不超过N组的指令。

$1\leq N \leq 10^{4}$

保证指令中需要加密和解密的字符串符合如下规则。
需要加密的字符串内，不会出现大写字母。
需要解密的字符串内，不会出现小写字母。
且$1\leq len(字符串) \leq 10^{3}$

## 输出描述:

根据指令进行输出

## 示例1

**输入**

```
International Collegiate Programming Contest
encryption
i want to win an icpc asian regional gold medal!
decryption
C WIBQ QD WCB IB CTFT IKCIB JROCDBIM ODME SREIM!
encryption
the international collegiate programming contest is awarded 10% gold, 20% silver, 30% bronze, and a maximum of 210 medals.
decryption
QLR CBQRJBIQCDBIM TDMMROCIQR FJDOJISSCBO TDBQRKQ CK IWIJERE 10% ODME, 20% KCMVRJ, 30% NJDBZR, IBE I SIXCSUS DA 210 SREIMK.
END
```

**输出**

```
C WIBQ QD WCB IB CTFT IKCIB JROCDBIM ODME SREIM!
i want to win an icpc asian regional gold medal!
QLR CBQRJBIQCDBIM TDMMROCIQR FJDOJISSCBO TDBQRKQ CK IWIJERE 10% ODME, 20% KCMVRJ, 30% NJDBZR, IBE I SIXCSUS DA 210 SREIMK.
the international collegiate programming contest is awarded 10% gold, 20% silver, 30% bronze, and a maximum of 210 medals.
Thanks for using goodbye!
```