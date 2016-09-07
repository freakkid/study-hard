how to use git
创建版本库 - 廖雪峰的官方网站  http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013743256916071d599b3aed534aaab22a0db6c4e07fd0000

open Git Bash//login
git config --global user.name freakkid
git config --global user.email 904811062@qq.com

pwd                                               //显示当前目录
cd <file>
git init                                          //把这个目录变成Git可以管理的仓库
git add <file>									  //把文件添加到暂存区
								//告诉Git，把（暂存区）文件提交到仓库（当前分支）
git commit -m "information"     
git remote add origin git@github.com:freakkid/***.git
git push -u origin master

远程要同步 都要push… 本地要同步远程要pull

git clone git@github.com:freakkid/***.git

git log 							//查看历史操作
git log --pretty=oneline			//查看历史操作（简洁版）
cat <file>							//查看文件内容
git diff readme.txt      			//查看修改的不同
git reset --hard HEAD^ 				//返回上一个版本
git reset --hard （版本编号）       //返回某个版本
git reflog  						//可以看到完整的版本

********修改文件*******
git status
git checkout -- readme.txt        //撤销文件修改
//改乱了工作区某个文件的内容，想直接丢弃工作区的修改
git checkout -- file
//改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步
git reset HEAD file
git checkout -- file

******删除文件******
rm <file> 								//删除文件
（1.正常）
git rm  <file>							//删除一个文件
git commit~
（2.天呐，删错了）
git checkout -- test.txt         		//恢复到版本库里的版本


//git checkout -- 用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”





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

