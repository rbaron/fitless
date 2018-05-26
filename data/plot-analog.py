import matplotlib.pyplot as plt
import re

from collections import defaultdict

REGEX = r'PIN (?P<pin>\d+): (?P<val>\d+)'

def read_input(filename):
    timeseries_by_pin = defaultdict(list)

    with open(filename) as f:
        for l in f:
            match = re.match(REGEX, l)
            if match:
                data = match.groupdict()
                timeseries_by_pin[data['pin']].append(int(data['val']))

    return timeseries_by_pin


def main():
    timeseries_by_pin = read_input('shake.log')
    for pin, values in timeseries_by_pin.items():
        if int(pin) in [3, 4, 5, 26]:
            plt.plot(values, label='Pin {}'.format(pin))

    plt.ylabel('Voltage*5/1024')
    plt.xlabel('Iteration')
    plt.title('Effect of shaking the board on some analog inputs')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    main()
