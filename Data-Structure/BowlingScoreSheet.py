class BowlingScoreSheet:

    def __init__(self):
        self.bowls = 0
        self.IsStrike = False
        self.IsSpare = False
        self.score = 0
        self.frameScore = [0] * 10

    def record(self, pins_knocked_down):
        ro = self.bowls // 2
        self.frameScore[min(9, ro)] += pins_knocked_down
        if self.IsStrike:
            if ro <= 9:
                self.score += 2 * pins_knocked_down
            else:
                self.score += pins_knocked_down
            if ro <= 9:
                self.frameScore[ro - 1] += pins_knocked_down
            self.IsStrike = False
            self.IsSpare = True
        elif self.IsSpare:
            if ro <= 9:
                self.score += 2 * pins_knocked_down
            else:
                self.score += pins_knocked_down
            if ro <= 9:
                self.frameScore[ro - 1] += pins_knocked_down
            self.IsStrike = False
            self.IsSpare = False
        else:
            self.score += pins_knocked_down
        
        if self.bowls % 2 == 0 and self.frameScore[min(9, ro)] > 0 and self.frameScore[min(9, ro)] % 10 == 0:
            self.IsStrike = True
            self.IsSpare = False
            self.bowls += 1
        elif self.bowls % 2 == 1 and self.frameScore[min(9, ro)] > 0 and self.frameScore[min(9, ro)] % 10 == 0:
            self.IsStrike = False
            self.IsSpare = True
        self.bowls += 1

    def get_frame_score(self, frame):
        return self.frameScore[frame - 1]
    
    def get_score(self):
        return self.score


if __name__ == "__main__":
    B = BowlingScoreSheet()
    score = [10, 10, 10, 10, 9, 1, 10]
    for idx, s in enumerate(score):
        B.record(s)