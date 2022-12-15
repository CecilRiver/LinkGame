# LinkGame 连连看

2022 年专业课程综合实训 I 期末大作业：基于 Qt 的桌面连连看游戏。

## 功能

- 账号注册与登录，分数保存到本地 SQLite
- 简单 / 普通 / 困难三种难度，随机生成关卡
- 三折线以内的连接判定，支持提示（每局 2 次）和重置（每局 2 次）
- 计时，每消除 6 对奖励 3 秒
- 分数统计与排行榜图表
- 背景音乐、消除音效、暂停/继续、自动求解、新手引导
- 基于 TCP 的双人联机，可查看对手剩余方块数

## 技术栈

- C++ / Qt 5（Widgets、Multimedia、Sql、Charts、Concurrent）
- qmake 构建
- SQLite（运行后生成 `MyData.db`）

## 目录结构

```
src/mainwindow.*     主界面与消除逻辑
src/clientwidget.*   TCP 联机客户端
src/logwidget.*      登录 / 注册
src/dialog.*         分数查询与图表
src/greenteach.*     新手引导
src/data.*           SQLite 数据访问
resources/           图片与音效
resources.qrc        Qt 资源清单
```

## 构建运行

1. 安装 Qt 5.x，包含 Qt Charts、Qt Multimedia 模块。
2. 用 Qt Creator 打开 `LinkGame.pro`，选择对应 Kit。
3. 构建并运行。

## 说明

仓库未包含部分界面背景图（`background*.jpg`）和新手引导图（`teachresources/1-4.jpg`），缺失时对应界面不显示背景或引导图，不影响核心玩法。
