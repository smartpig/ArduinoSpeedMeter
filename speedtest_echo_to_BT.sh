echo "`curl -f -w "%{speed_download}" http://speedtest.wdc01.softlayer.com/downloads/test100.zip -o /dev/null` / 131072" | bc | xargs -I {} > /dev/tty.HC-05-DevB
