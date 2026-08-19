# 智乃与瞩目狸猫、幸运水母、月宫龙虾

## 题目描述

Ubuntu是一个以桌面应用为主的Linux发行版操作系统，其名称来自非洲南部祖鲁语或豪萨语的"ubuntu"一词，意思是"人性"、"我的存在是因为大家的存在"，是非洲传统的一种价值观。

在ubuntu系统下，命令行执行

```bash
lsb_release -a
```

![lsb_release输出](https://uploadfiles.nowcoder.com/images/20231202/0_1701513936985/26FA7ED979F90406B0860E7696FA7634)

可以看到代号(Codename)，到目前为止，Ubuntu 发行版的每个代号都包含一个形容词和一个动物。例如：瞩目狸猫(Focal Fossa)、幸运水母(Jammy Jellyfish)、月宫龙虾(Lunar Lobster)，每个代号的两个单词首字母相同。

![Ubuntu代号](https://uploadfiles.nowcoder.com/images/20231202/0_1701514030174/9C3E677570369A1F08374505BE858811)

在不考虑单词词性的前提下，只要求两个单词的**首字母****忽略大小写相同**时就认为它们可能是一组ubuntu代号，请你编写程序判断给定的两个单词是否可能是一个ubuntu代号。

## 输入描述

第一行输入一个正整数 $T(1\leq T \leq 10^{5})$，表示测试用例的组数。

对于每组测试用例，输入一行两个单词 $S,T(1 \leq |S|,|T|\leq 50)$，单词仅包含大小写英文字母。

## 输出描述

对于每组测试用例，如果它可能是一组ubuntu代号，则输出"Yes"，否则输出"No"。裁判程序将忽略大小写，你可以输出任意大小写的"Yes"和"No"。

## 示例1

### 输入

```text
1
jammy jellyfish
```

### 输出

```text
Yes
```

## 示例2

### 输入

```text
13
Artful Aardvark
Bionic Beaver
Cosmic Cuttlefish
Disco Dingo
Eoan Ermine
Focal Fossa
Groovy Gorilla
Hirsute Hippo
Impish Indri
Jammy Jellyfish
Kinetic Kudu
Lunar Lobster
Avada Kedavra
```

### 输出

```text
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes
Yes
No
```