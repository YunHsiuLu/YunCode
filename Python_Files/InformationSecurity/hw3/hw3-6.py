import requests
import time

N = 20330970518755266242385905909493999137973424517956750150773387949450532738688140473016222471696353578971086244369854380559140307733766358995413733184270019263360966196480889892663449165581262567418515172910299228349764975639022173337717299671010360499385345258618681931950804787900352965945845764611738623330333991461000238591512750434491144339028770929223044620312099262465034253568878440783320799163740718510059832988003082752355931321805914693636091553425020056741155485595996089729505271434927528288363505735195072563272004104479612256661159085577310689018439362584786110537353301294577002586849490834964662377009
e = 176017195937730623562123747592078013189155197074053280649770136474672968778215745823517885186913756941022137245391137597807350100567017396357885051013778874401683908206146763549324783662154975115658507034180653906388362323548765829068065774694214943095348097082200118107056345501727632545607469759685883132593
c = 7473532755260641751851958007580881263839596031188905104988191160700873048118683086460917048233183580620071267702465699659368846043441508499408174074721199816517942387597065088661094088272494191071671734615014841721514200075452817658516007175840064121120971889701376909520593117661021321868959724741292024175597099904777587171043492976527217258989426859827500956973545739556786392893508222989463612768269690954526982275598416240996192338630459952345918103782741200724744412619167103657821866999303598889544753723617786704152213782849892834619193581116565438088272135301424018695818792471033078943045831440924081480070
tc = hex(c)[2:]
hc = [tc[i:i+2] for i in range(0, len(tc), 2)]
#print(hc)
start = time.time()
test = c * 2**e
URL = "http://140.122.185.210:8080/oracle/"
URL += str(test)
r = requests.get(URL)
print(r.text)
end = time.time()
print(f"time: {end-start} s")