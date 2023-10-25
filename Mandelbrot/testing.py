#!/usr/bin/env python3
import os # to clear terminal and get width and height

class Fractal:
    def __init__(self, iterations: int, cutoff: float) -> None:
        self.spectrum = [' ', '.', ',', '_', ':', ';', '+', '~', '=', '%', '#']
        self.iterations = iterations

        # % of max iterations too low to color
        self.cutoff = cutoff
    
    
    def set_iteratons(self, iterations: int):
        self.iterations = iterations


    def sample_julia(self, point: complex, term: complex) -> str:
        i = 0
        z = point
        while i < self.iterations - 1:
            z = (z * z) + term

            # Point is outside the set
            if z.real * z.real + z.imag * z.imag > 4:
                break

            i += 1
        
        gradient = max(0, ((i / self.iterations) - self.cutoff) / (1 - self.cutoff))
        return self.spectrum[int(gradient * len(self.spectrum))]


    '''
        z_(n+1) = z_n^2 + c
        z_0 = 0 + 0j
        c is the point to test

        c is in the set if the sequence z is bounded
        all |c| > 2 is outside the set
    '''
    def sample_mandelbrot(self, point: complex) -> str:
        i = 0
        z = complex()
        while i < self.iterations - 1:
            z = (z * z) + point

            # Point is outside the set
            if z.real * z.real + z.imag * z.imag > 4:
                break

            i += 1
        
        gradient = max(0, ((i / self.iterations) - self.cutoff) / (1 - self.cutoff))
        return self.spectrum[int(gradient * len(self.spectrum))]


'''
    Render fractal with view centered at center

    Paramaters:
        term_w: width of terminal in characters
        term_h: height of terminal in lines
        w: width of viewport on the real axis
        center: center of viewport in complex form
        term: term for Julia set
'''
def draw(term_w: int, term_h: int, w: float, center: complex, term: complex, fractal: Fractal, mode: int) -> None:
    # Rescale complex axis so that the viewport is 1-1 with screen
    h = w * (term_h / term_w) * 2.113

    # Precalculate distances between characters
    delta = complex(w / term_w, h / term_h)

    start = center - complex(w / 2, h / 2)
    point = start

    # Init output
    output = ""

    # Sample every cell in the terminal
    for Y in range(term_h):
        point = complex(start.real, point.imag)
        for X in range(term_w):
            if mode == 0:
                output += fractal.sample_mandelbrot(point)
            else:
                output += fractal.sample_julia(point, term)
            
            point += delta.real
        
        output += '\n'
        point += delta.imag*1j
    
    # Clear terminal
    os.system("clear")

    # Output to terminal
    print(output)




def main() -> None:
    fractal = Fractal(100, 0.05)
    func = 0

    scale = 4.0
    m_scale = 4.0
    center = complex()
    m_center = complex()
    
    while(True):
        width = os.get_terminal_size().columns
        height = os.get_terminal_size().lines
        
        draw(width, height, scale, center, m_center, fractal, func)

        l = input()
        if l.isdigit():
            fractal.set_iteratons(int(l))
        else:
            for i in l:
                match i:
                    case 'a':
                        center -= complex(0.1 * scale, 0.0)
                    case 'd':
                        center += complex(0.1 * scale, 0.0)
                    case 'w':
                        center -= complex(0.0, 0.1 * scale)
                    case 's':
                        center += complex(0.0, 0.1 * scale)

                    case 'q':
                        scale *= 1.5
                    case 'e':
                        scale /= 1.5

                    case 'j':
                        m_center -= complex(0.1 * m_scale, 0.0)
                    case 'l':
                        m_center += complex(0.1 * m_scale, 0.0)
                    case 'i':
                        m_center -= complex(0.0, 0.1 * m_scale)
                    case 'k':
                        m_center += complex(0.0, 0.1 * m_scale)
                        
                    case 'g':
                        if func == 0:
                            func = 1
                            m_center = center
                            center = complex()
                            m_scale = scale
                            scale = 4.0
                        else:
                            func = 0
                            scale = m_scale
                            center = m_center




if __name__ == "__main__":
    main()
