git rm site.conf

for /d %%d in (*.*) do (
    set test=%%d
    echo !test!
)
pause

git pull origin master
git add .
git commit -m "Auto"
git push origin master