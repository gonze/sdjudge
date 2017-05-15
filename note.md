
1.库的问题，可以不启动服务，打开bin文件夹中打OJdaemon,看看错误。
   ldconfig命令的作用，搜寻目录，以及动态配置文件所有目录，创建链接，
2.systemctl命令
使某服务自动启动:systemctl enable OJdaemon.service

检查服务状态：systemctl status OJdaemon.service （服务详细信息）
              systemctl is-active OJdaemon.service （仅显示是否 Active)
显示所有已启动的服务：systemctl list-units --type=service
启动某服务：systemctl start OJdaemon.service
停止：systemctl stop OJdaemon.service
重启：systemctl restart OJdaemon.service    
3.如果不能自动建文件夹，手动，建立下面些文件

/mnt/sdoj_temp/temp

