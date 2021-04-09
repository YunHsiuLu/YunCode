import random
import time
a = []
b = [1, 2, 3, 4, 5, 6, 7, 8]
for i in range(38):
    a.append(i+1)

# 定義威力彩class


class taiwanlottery:
    def __init__(self):
        self.first = []
        self.second = 0
        self.win = False

# 定義兌獎方式


def CheckWin(number, choose):
    first = 0
    second = False
    for i in range(6):
        for j in range(6):
            if choose.first[i] == number[0][j]:
                first += 1
    second = (number[1] == choose.second)
    if first == 6 and second:
        return "頭獎", 1
    elif first == 6 and not second:
        return "貳獎", 2
    elif first == 5 and second:
        return "參獎", 3
    elif first == 5 and not second:
        return "肆獎", 4
    elif first == 4 and second:
        return "伍獎", 5
    elif first == 4 and not second:
        return "陸獎", 6
    elif first == 3 and second:
        return "柒獎", 7
    elif first == 2 and second:
        return "捌獎", 8
    elif first == 3 and not second:
        return "玖獎", 9
    elif first == 1 and second:
        return "普獎", 10
    else:
        return "沒中獎QQ", -99


def GiveMoney(win):
    if win == 1:
        return 1000000000
    elif win == 2:
        return 10000000
    elif win == 3:
        return 150000
    elif win == 4:
        return 20000
    elif win == 5:
        return 4000
    elif win == 6:
        return 800
    elif win == 7:
        return 400
    elif win == 8:
        return 200
    elif win == 9:
        return 100
    elif win == 10:
        return 100
    else:
        return 0


def CountWins(CC):
    print("得到的獎項:\n")
    print("頭獎: %d" % (CC.count(1)))
    print("貳獎: %d" % (CC.count(2)))
    print("參獎: %d" % (CC.count(3)))
    print("肆獎: %d" % (CC.count(4)))
    print("伍獎: %d" % (CC.count(5)))
    print("陸獎: %d" % (CC.count(6)))
    print("柒獎: %d" % (CC.count(7)))
    print("捌獎: %d" % (CC.count(8)))
    print("玖獎: %d" % (CC.count(9)))
    print("普獎: %d" % (CC.count(10)))
    print("沒中獎: %d" % (CC.count(-99)))


while(1):
    print("-------------若要退出，請按Ctrl+c-------------\n")
    money = int(input("設定起始金額\n"))
    print("你現在餘額: %d" % (money))
    while(money > 0):
        count = []
        time.sleep(0.6)
        sets = int(input("你要買幾組?  "))
        # 判斷剩餘金額是否足夠
        if (sets*100 > money):
            print("######餘額不足######\n")
            t = -999
            while(1):
                b = input("是否要繼續?(yes/no)  ")
                if b == "yes":
                    t = 0
                    break
                elif b == "no":
                    t = 1
                    break
                else:
                    t = 2
                    continue
            if t == 0:
                continue
            elif t == 1:
                break
        money -= sets*100
        # 是否電腦選號
        b_com = input("是否進行電腦選號?(yes/no) ")
        b_pri = bool(input("是否顯示出所有選號?(yes/no) ") == "yes")
        # 中獎號碼
        the_number = [random.sample(a, 6), random.choice(b)]
        # 是電腦選號
        if b_com == "yes":
            print("威力彩電腦選號: ")
            if not b_pri:
                print("Loading......")
            for i in range(sets):
                temp = taiwanlottery()
                temp.first = random.sample(a, 6)
                temp.second = random.choice(b)
                s, w = CheckWin(the_number, temp)
                if b_pri:
                    print("  第%d組號碼: " % (i+1), temp.first,
                          "\t", temp.second, "\t", s)
                money += GiveMoney(w)
                count.append(w)
        # 不是電腦選號
        elif b_com == "no":
            for i in range(sets):
                temp = taiwanlottery()
                print("第%d組號碼" % (i+1))
                j = 0
                while(j < 6):  # 判斷輸入號碼是否符合規則
                    j += 1
                    cc = int(input("請輸入欲挑選之號碼: \n"))
                    if cc <= 0 or cc > 38:
                        print("不符合規則\n")
                        j -= 1
                        continue

                    (temp.first).append(cc)
                while(1):  # 判斷輸入特別號是否符合規則
                    cc_ = int(input("請輸入欲挑選支特別號: \n"))
                    if cc_ <= 0 or cc_ > 8:
                        print("不符合規則\n")
                    else:
                        temp.second = cc_
                        break
                s, w = CheckWin(the_number, temp)
                print("  第%d組號碼: " % (i+1), temp.first,
                      "\t", temp.second, "\t", s)
                money += GiveMoney(w)
                count.append(w)
        else:
            print("重新選擇\n")
            continue
        # 顯示出中獎號碼
        print("本期中獎號碼: ", the_number[0], the_number[1])
        print("你現在餘額: %d" % (money))
        # 計算得到的獎項
        CountWins(count)
        if money == 0:
            print("遊戲結束\n")
