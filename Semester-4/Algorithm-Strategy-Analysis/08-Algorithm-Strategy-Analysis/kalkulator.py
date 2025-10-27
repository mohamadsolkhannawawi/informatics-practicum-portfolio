from collections import deque

def min_operations(N):

    # Handle kasus khusus

    if N == 0:

        return 0

    

    queue = deque([(N, 0)])

    visited = set([N])

    

    while queue:

        current, ops = queue.popleft()

        

        # Periksa semua operasi yang mungkin

        

        # 1. Bagi dengan 3^n (untuk n≥0)

        # Mencoba operasi ini terlebih dahulu karena dapat menghasilkan pengurangan nilai yang signifikan

        divisor = 1

        while divisor <= current:

            if current % divisor == 0:

                result = current // divisor

                if result == 0:  # Langsung return jika hasil adalah 0

                    return ops + 1

                if result not in visited:

                    visited.add(result)

                    queue.append((result, ops + 1))

            divisor *= 3

            if divisor > current:  # Hentikan jika divisor melebihi current

                break

        

        # 2. Kalikan dengan 2

        # Ini dapat membantu menjadikan angka habis dibagi 3^n

        result = current * 2

        if result <= 10000 and result not in visited:  # Batasan yang lebih longgar

            visited.add(result)

            queue.append((result, ops + 1))

        

        # 3. Kurangi 1

        result = current - 1

        if result >= 0 and result not in visited:

            if result == 0:  # Langsung return jika hasil adalah 0

                return ops + 1

            visited.add(result)

            queue.append((result, ops + 1))

        

        # 4. Tambah 1

        result = current + 1

        if result <= 10000 and result not in visited:  # Batasan yang lebih longgar

            visited.add(result)

            queue.append((result, ops + 1))

    

    return -1  # Tidak mungkin mencapai 0 (seharusnya tidak terjadi)

# Input

N = int(input())

# Output

result = min_operations(N)

print(result)