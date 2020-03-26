import os
import heapq
import timeit

def read(path):
    try:
        print(f"Reading data for {path}")
        data = []
        file = open(path, "r").read()
        for line in file.split("\n"):
            if line != "\n":
                data.append([int(entry) for entry in line.strip().split()])
        return data
    except Error as error:
        console.log(error)

def parseData(data):
    print("Starting to parse data")
    assert len(data) % 2 == 0, "incorrect data length"
    n, sign, scan, books = [], [], [], []
    for i in range(2, len(data), 2):
        assert len(data[i]) == 3, "incorrect number of entries"
        assert len(data[i + 1]) == data[i][0], "incorrect number of books"
        n.append(data[i][0])
        sign.append(data[i][1])
        scan.append(data[i][2])
        books.append(data[i + 1][:])
    return n, sign, scan, books

def greedy(i, books, scores, sign, scan, collectedBooks, remainingDays):
    av = [b for b in books[i] if not b in collectedBooks]
    if len(av) <= (remainingDays - sign[i]) * scan[i]:
        return sum(scores[b] for b in av), av
    
    pq = []
    for book in av:
        heapq.heappush(pq, (-scores[book], book))

    value, choosenBooks = 0, []
    for c in range((remainingDays - sign[i]) * scan[i]):
        val, book = heapq.heappop(pq)
        choosenBooks.append(book)
        value += abs(val)
    return value, choosenBooks

def weightless(i, books, scores, sign, scan, collectedBooks, remainingDays):
    av = [b for b in books[i] if not b in collectedBooks]
    l = (remainingDays - sign[i]) * scan[i]
    if len(av) <= l:
        return scores[0] * len(av), av
    else:
        return scores[0] * l, av[:l]
    
def solution(B, L, D, scores, n, sign, scan, books, mode):
    # B (int): number of books overall
    # L (int): number of libraries
    # D (int): number of days
    # scores (array): score for each book
    # n (array): number of books
    # sign (array): time for sign up
    # scan (array): maximum number of scans per day
    # books (array of arrays): books in each library
    # mode: mode of selection
    assert mode in ("greedy", "weightless")
    collectedBooks, registeredLibraries = set(), set()
    libraryList, bookCount, ans = [], [], []

    total, libraryCount, remainingDays = 0, 0, D
    while remainingDays > 0:
        print(f"Days remaining: {remainingDays}")
        subtotal, bestBookPerDay, bestLibrary, found, details = 0, 0, 0, False, None
        for i in range(L):
            if i not in registeredLibraries and sign[i] < remainingDays:
                found = True
                if mode == "greedy":
                    value, choosenBooks = greedy(i, books, scores, sign, scan, collectedBooks, remainingDays)
                elif mode == "weightless":
                    value, choosenBooks = weightless(i, books, scores, sign, scan, collectedBooks, remainingDays)

                if value / sign[i] > bestBookPerDay:
                    bestBookPerDay, details, subtotal, bestLibrary = value / sign[i], choosenBooks, value, i

        if not found:
            remainingDays = 0
        else:
            remainingDays -= sign[bestLibrary]
            total += subtotal
            libraryCount += 1
            libraryList.append(bestLibrary)
            ans.append(details)
            bookCount.append(len(details))
            registeredLibraries.add(bestLibrary)
            for book in details:
                collectedBooks.add(book)
                
    return total, libraryCount, libraryList, bookCount, ans
    
def submit(path, libCnt, libOrder, bookCnt, bookOrder):
    print(f"Preparing submission: {path}")
    try:
        with open(path, mode="w") as file:
            file.write(str(libCnt) + "\n")
            counter = 0
            for i, j, k in zip(libOrder, bookCnt, bookOrder):
                file.write(str(i) + " " + str(j) + "\n")
                file.write(" ".join([str(v) for v in k]))
                counter += 1
                if counter < libCnt:
                    file.write("\n")
    except Error as error:
        print(error)

                
if __name__ == "__main__":
    dataPath = [f for f in os.listdir() if os.path.splitext(f)[-1] == ".txt"]
    submissionExt = "./submission/"
    print(f"Files: {dataPath}")
    for path in dataPath:
        print(f"\n\n\nBeginning submission for {path}")
        data = read(path)
        assert len(data[1]) == data[0][0], "incorrect number of score parameters"
        assert len(data[0]) == 3, "incorrect number of parameters"
        assert len(data) == 2 + 2 * data[0][1], "incorrect number of lines"

        B, L, D = data[0]
        scores = data[1]
        n, sign, scan, books = parseData(data)

        print(f"Max possible value: {sum(scores)}")
        print()
        print("-" * 50)
        print("Inputs")
        print("-" * 50)
        print()
        print(f"B: {B}, L: {L}, D: {D}")
        
##      print(f"Book scores: {scores}")
##      print(f"Number of books in each library: {n}")
##      print(f"Days for sign up: {sign}")
##      print(f"Maximum number of scans per day in each library: {scan}")
##      print(f"Books in each library: {books}")
##      print()
##      print()

        # solution
        start = timeit.default_timer()
        mode = "weightless" if len(set(scores)) == 1 else "greedy"
        total, libraryCnt, libraryList, bookCount, ans = solution(B, L, D, scores, n, sign, scan, books, mode)
        print(f"Time elapsed: {timeit.default_timer() - start}")

        # error checking
        assert libraryCnt == len(libraryList), "invalid solution"
        assert libraryCnt == len(bookCount), "invalid solution"
        assert libraryCnt == len(ans), "invalid solution"

        # check for duplicates
        vs = set()
        for lib in ans:
            for book in lib:
                assert not book in vs and 0 <= book < B, "duplicate found"
                vs.add(book)

        print("-" * 50)
        print("Outputs")
        print("-" * 50)
        print()
        print(f"Total points: {total}")
        
##      print(f"Number of libraries: {libraryCnt}")
##      print(f"Libraries visited in order: {libraryList}")
##      print(f"Number of books scanned in each library: {bookCount}")
##      print(f"Books collected at each library in order: {ans}")
##      print()
##      print()

        # create submission
        submissionPath = submissionExt + os.path.splitext(path)[0] + "_submission.txt"
        submit(submissionPath, libraryCnt, libraryList, bookCount, ans)
