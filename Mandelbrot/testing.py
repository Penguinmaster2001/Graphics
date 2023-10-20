#!/usr/bin/env python3

max_iter = 50
spec = [' ', '.', ',', ':', ';', '-', '+', '~', '=', '%', '#']

'''
    z_(n+1) = z_n^2 + c
    z_0 = 0 + 0j
    c is the point to test

    c is in the set if the sequence z is bounded
    all |c| > 2 is outside the set
'''
def val(c: complex) -> str:
    z = complex()

    for i in range(max_iter):
        z = (z * z) + c
        if abs(z) > 2:
            break
    
    l = 0.3
    m = max(0, ((i / max_iter) - l) / (1 - l))
    return spec[int(m * len(spec))]


'''
    Move through a 2d space, writing ' ' if outside,
    '*' if inside
'''
def draw(term_w: int, term_h: int, w: float, start_r: float, start_c: float) -> None:
    d_c = 6 * w / term_w
    d_r = w / term_h

    output = ""

    c = start_c
    for X in range(term_h):
        c += d_c
        r = start_r
        for Y in range(term_w):
            r += d_r

            output += val(complex(r, c))
        
        output += '\n'
    
    print(output)


def main() -> None:
    draw(284, 100, 0.1, -1.5, -0.01)


if __name__ == "__main__":
    main()
