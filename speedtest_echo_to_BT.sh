echo "`curl -f -w "%{speed_download}" http://speedtest.wdc01.softlayer.com/downloads/test500.zip -o /dev/null` / 131072" | bc | xargs -I {} > /dev/cu.AdafruitEZ-Link8a57-SPP