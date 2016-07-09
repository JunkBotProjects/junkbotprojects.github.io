set count=
for /d %%a in (H:\junkbotprojects.github.io\projects\*) do set /a count+=1
echo %count%

@echo { > site.conf
@echo 	"site":{ >> site.conf
@echo 		"project":{ >> site.conf
@echo 			"count" : %count% >> site.conf
@echo 		} >> site.conf
@echo 	} >> site.conf
@echo } >> site.conf

git pull origin master
git add .
git commit -m "Auto"
git push origin master