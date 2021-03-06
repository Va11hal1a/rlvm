World:import("LB_lib.lua")
LB:installMainMenuHandler()
LB:clickThroughMinigames()
LB:installRandomDecisionHandler()

-- Rin
-- Adapted from http://gamerssquare.kanpaku.jp/littlebusters.htm#r8
decisions = {
    -- May 14th
    "声をかける",
    "いい",
    "いい",
    "いい",
    "いい",
    --※佐々美戦、敗北でＯＫ
    --※ここで佐々美バトル設定”ON/OFF”
    --※鈴を３Fへ。一応成功させる。失敗した時は右クリック、”前の選択肢に戻る”でやり直せます
    -- May 15th
    "貸さない",
    "探しに行く",
    "声をかける",
    --※バッティング設定”ON/OFF”
    --※鈴VS真人。バトルランキング設定”ON/OFF”
    --※以降、バトル、ミッションは基本的に記述省略
    -- May 16th
    "鈴を追う",
    "声をかける",
    "先を急ぐ",
    "自分で行ってもらう",
    "終わりにする",
    "あまり関わらないでおく",
    -- May 17th
    "ない",
    "やっぱり止める",
    "鈴を追う",
    "声をかける",
    "屋上にいかない",
    -- ※佐々美と対戦
    -- May 18th
    -- ※配膳ミッション
    "学食に戻る",
    "真人と遊ぶ",
    "黙って成り行きを見守る",
    -- May 19th
    "鈴を探す",
    "声をかける",
    "表に出る",
    "立ち去る",
    "大人しく過ごす",
    "宿題が…",
    -- May 20th
    "いかない",
    "いかない",
    "好き",
    "恭介",
    "ふわふわストロベリードーナツ",
    -- May 21st
    "しっかり読む",
    "真人と遊ぶ",
    "終わりにする",
    "謙吾",
    "真人",
    "鈴",
    -- May 22nd
    "真人と遊ぶ",
    "学食にいく",
    "先にいく",
    "真人",
    "恭介を追う",
    "練習に集中",
    "いく", --　※風呂CG
    -- May 23rd
    "話を進める",
    "手伝い続ける",
    -- These three choices are chosen through handleTimedChoices() instead of
    -- the normal decision handler path.
    --
    -- "邪魔だろ",
    -- "そこまででかくなるか！",
    -- "みんなの服に飛び散っただろ",
    "ジュースを買いに行く",
    "練習に集中",
    "そんな目で見続ける",
    "放っておく",
    "学食に急ぐ",
    "やめておく",
    "恭介の部屋にいく",
    "みんなを呼ぶ",
    -- May 24th
    "ジュースを買いに行く",
    "見送る",
    "猫を探してみる",
    "練習に集中",
    "止めない",
    "鈴",
    "葉留佳",
    -- May 25th
    "鈴に相談",
    "廊下を走り抜ける",
    "助けてもらう",
    "終わりにする",
    -- ※一旦セーブ。お好みで他の選択肢も試す
    "ウサギ",
    "ジョー",
    -- 鈴
    "励ます",
    "挙手する",
    "中庭",
    "いく", --　※反対の選択肢でBADエンド
    -- ※一旦エンドロール
    "これからは強く生きる"
}

World:setDecisionList(decisions)

LB:handleTimedChoices({"邪魔だろ！！",
                       "そこまででかくなるか！！",
                       "みんなの服に飛び散っただろ！！"})
