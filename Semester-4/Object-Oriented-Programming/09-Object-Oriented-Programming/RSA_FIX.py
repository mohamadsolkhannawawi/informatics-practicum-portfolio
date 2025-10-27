import math

def is_prime(n):
    """Check if a number is prime."""
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def gcd(a, b):
    """Calculate the Greatest Common Divisor using Euclidean algorithm."""
    while b:
        a, b = b, a % b
    return a

def mod_inverse(e, phi):
    """Find modular multiplicative inverse using extended Euclidean algorithm."""
    def extended_euclidean(a, b):
        if a == 0:
            return b, 0, 1
        else:
            gcd, x, y = extended_euclidean(b % a, a)
            return gcd, y - (b // a) * x, x

    k = 1
    while True:
        d = (1 + k * phi) // e
        gcd, x, y = extended_euclidean(e, phi)
        if gcd == 1 and (e * d) % phi == 1:
            return d
        k += 1

def generate_rsa_keypair(p, q, e):
    """Generate RSA key pair following the example in the document."""
    print("\n" + "="*50)
    print("STEP 1: KEY GENERATION")
    print("="*50)
    
    # Verify primes
    print(f"1.1 Checking primes: p = {p}, q = {q}")
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Both numbers must be prime.')
    print("1.2 Primes verified successfully!")
    
    # Compute n
    n = p * q
    print(f"\n1.3 Computing n: n = p * q = {p} * {q} = {n}")
    
    # Compute Euler totient function φ(n)
    phi = (p - 1) * (q - 1)
    print(f"1.4 Computing φ(n): φ(n) = (p-1) * (q-1) = {p-1} * {q-1} = {phi}")
    
    # Choose e (public key exponent)
    print(f"\n1.5 Choosing e: e = {e}")
    
    # Verify e is coprime to phi
    print(f"1.6 Checking if e is coprime to φ(n)")
    if gcd(e, phi) != 1:
        raise ValueError('e must be coprime to φ(n)')
    print("1.7 e is coprime to φ(n)!")
    
    # Compute private key d
    d = mod_inverse(e, phi)
    print(f"\n1.8 Computing private key d: d = {d}")
    print(f"1.9 Verifying: (e * d) mod φ(n) = {(e * d) % phi}")
    
    return {
        'n': n,
        'e': e,  # Public key
        'd': d   # Private key
    }

def detailed_modular_exponentiation(base, exponent, modulus, step_detail=None):
    """
    Perform detailed modular exponentiation with explicit step-by-step calculation
    """
    print(f"\n{step_detail or '2.4'} Detailed Modular Exponentiation:")
    prefix = step_detail.split('.')[0] if step_detail else '2.4'
    sub_prefix = step_detail.split('.')[-1] if step_detail else '4'
    
    print(f"{prefix}.{sub_prefix}.1 Base : {base}")
    print(f"{prefix}.{sub_prefix}.2 Exponent = e : {exponent}")
    print(f"{prefix}.{sub_prefix}.3 Modulus = n : {modulus}")
    
    # Prepare powers
    print(f"\n{prefix}.{sub_prefix}.4 Individual Power Calculations:")
    powers = {1: base % modulus}
    max_power = 1
    power_details = [(1, powers[1])]
    
    # # Start with base^1 // Double hasilnya
    # print(f"     {base}^1 mod {modulus} = {powers[1]}")
    
    # Start with base^1 as the initial power
    print(f"     {base}^1 mod {modulus} = {powers[1]}")
    
    # Catatan: Perhitungan pangkat dilakukan dengan cara:
    # 1. Mulai dari base^1
    # 2. Untuk setiap pangkat selanjutnya (2, 4, 8, dst), 
    #    dihitung dengan mengalikan pangkat sebelumnya dengan dirinya sendiri
    # 3. Selalu menggunakan modulo untuk menjaga bilangan tetap kecil
    
    # Generate powers dynamically
    while max_power < exponent:
        next_power = max_power * 2
        
        # Calculate how the power is derived
        if max_power == 1:
            powers[next_power] = (powers[max_power] * powers[max_power]) % modulus
            print(f"     {base}^{next_power} mod {modulus} = ({base}^{max_power} x {base}^{max_power}) mod {modulus} = {powers[next_power]}")
        else:
            powers[next_power] = (powers[max_power] * powers[max_power]) % modulus
            print(f"     {base}^{next_power} mod {modulus} = ({base}^{max_power} x {base}^{max_power}) mod {modulus} = {powers[max_power]} x {powers[max_power]} mod {modulus} = {powers[next_power]}")
        
        power_details.append((next_power, powers[next_power]))
        max_power = next_power
    
    # Determine which powers contribute to the final result
    contributing_powers = []
    remaining_exponent = exponent
    current_power = 1
    while remaining_exponent > 0:
        if remaining_exponent % 2 == 1:
            contributing_powers.append(current_power)
        remaining_exponent //= 2
        current_power *= 2
    
    # Explicit calculation notation
    print(f"\n{prefix}.{sub_prefix}.5 Detailed Calculation:")
    print(f"     C = {base}^{exponent} mod {modulus}")
    
    # Prepare calculation string
    powers_str = " + ".join(map(str, contributing_powers))
    print(f"     = {base}^({powers_str}) mod {modulus}")
    
    # Detailed intermediate steps
    print(f"\n{prefix}.{sub_prefix}.6 Detailed Step-by-Step Calculation:")
    
    # Create a detailed breakdown of powers
    detailed_power_info = {power: details for power, details in power_details}
    
    # Actual detailed calculation
    result = 1
    detailed_steps = []
    step_details = []
    
    for i, power in enumerate(contributing_powers, 1):
        # Get the modular power for this step
        current_mod_power = detailed_power_info[power]
        
        # Prepare step details
        if i == 1:
            # First step is just the first mod power
            step_result = current_mod_power
            detailed_step = f"Step {i}: {result} * ({base}^{power} mod {modulus}) = {current_mod_power}"
        else:
            # Subsequent steps multiply previous result with current mod power
            step_result = (result * current_mod_power) % modulus
            detailed_step = f"Step {i}: ({result} * {current_mod_power}) mod {modulus} = {step_result}"
        
        # Store step details
        result = step_result
        detailed_steps.append(detailed_step)
        step_details.append((power, current_mod_power, result))
    
    # Print detailed steps
    for step in detailed_steps:
        print(f"     {step}")
    
    # Print step details summary
    print(f"\n{prefix}.{sub_prefix}.7 Step Details Summary:")
    for power, mod_power, step_result in step_details:
        print(f"     {base}^{power} mod {modulus} = {mod_power}")
    
    print(f"\n{prefix}.{sub_prefix}.8 Final Result: {result}")
    return result

def rsa_encrypt(plaintext, e, n):
    """Encrypt the plaintext using RSA encryption."""
    print("\n" + "="*50)
    print("STEP 2: ENCRYPTION")
    print("="*50)
    
    # Convert plaintext to integer
    M = int(plaintext)
    print(f"2.1 Plaintext: {M}")
    print(f"2.2 Public key (e, n): ({e}, {n})")
    
    # Encrypt: C = M^e mod n
    C = detailed_modular_exponentiation(M, e, n)
    
    print(f"\n2.3 Ciphertext C = {M}^{e} mod {n} = {C}")
    return C

def rsa_decrypt(ciphertext, d, n):
    """Decrypt the ciphertext using RSA decryption."""
    print("\n" + "="*50)
    print("STEP 3: DECRYPTION")
    print("="*50)
    
    print(f"3.1 Ciphertext: {ciphertext}")
    print(f"3.2 Private key (d, n): ({d}, {n})")
    
    # Decrypt: M = C^d mod n
    M = detailed_modular_exponentiation(ciphertext, d, n, step_detail='3.3')
    
    print(f"\n3.4 Decrypted plaintext M = {ciphertext}^{d} mod {n} = {M}")
    return M

def main():
    # Example values
    e = 7
    p, q = 11, 17
    
    # Generate RSA key pair
    keys = generate_rsa_keypair(p, q, e)
    print("\n" + "="*50)
    print("STEP 2: FINAL KEY DETAILS")
    print("="*50)
    print(f"n = {keys['n']}")
    print(f"e = {keys['e']}")
    print(f"d = {keys['d']}")
    
    # Example plaintext
    plaintext = 88
    
    # Encrypt
    ciphertext = rsa_encrypt(plaintext, keys['e'], keys['n'])
    
    # Decrypt
    decrypted = rsa_decrypt(ciphertext, keys['d'], keys['n'])
    
    # Verify
    print("\n" + "="*50)
    print("STEP 4: VERIFICATION")
    print("="*50)
    print(f"4.1 Original Plaintext: {plaintext}")
    print(f"4.2 Decrypted Plaintext: {decrypted}")
    assert decrypted == plaintext, "Decryption failed!"
    print("4.3 Verification Successful!")

if __name__ == "__main__":
    main()