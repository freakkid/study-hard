how to use git
创建版本库 - 廖雪峰的官方网站  http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013743256916071d599b3aed534aaab22a0db6c4e07fd0000

open Git Bash//login
git config --global user.name freakkid
git config --global user.email 904811062@qq.com

cd <file>
git init
git add <file>
git commit -m "information"
git remote add origin git@github.com:freakkid/***.git
git push -u origin master

远程要同步 都要push… 本地要同步远程要pull

git clone git@github.com:freakkid/***.git

------------------------------------关于可能出现的错误-----------------------------
1.在执行
$ git remote addorigin git@github.com:defnngj/hello-world.git
错误提示：fatal: remote origin already exists.
解决办法：
$ git remote rm origin

2. 在执行
$ git push origin master
错误提示：error:failed to push som refs to.......
解决办法：
$ git pull origin master // 先把远程服务器github上面的文件拉下来，再push 上去。
(或者试一下git pull?)



----------------------------------------------------------------------
git的操作对象叫做仓库… 一个仓库就是一个repository 要删除 要在github的setting里delete
要删除 只需要git pull下来全删了然后git add --all  git commit  git push

