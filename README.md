# Card Counting Simulator

This program is designed to accurately imitate a real-life blackjack game, and to help estimate EV (expected value) for playing blackjack as a card counter.

To run the program:

    make compile

    make run

## Rules
To run the program with a different ruleset, you can update `options.txt`.

Use the format `rulename:rulevalue` with a newline separating each rule.

`decks - 2, 4, 6, 8`: The number of decks in the shoe.

`h17 - true, false`: Whether or not the dealer hits on a soft 17 or not.

`das - true, false`: Whether the player is allowed to double after split.

`variants - true, false`: Whether to change basic strategy based on the true count.

`counting_strategy - hilo`: What card counting technique to use.

`blackjack_payout - 1.5, 1.2`: How much the player is payed upon receiving a blackjack.

`resplit_limit - 2, 3, 4`: The max number of decks a player can resplit to.

## Static Rules

These rules are built into the program.

**Bet Spread**: Multiply the betting unit by the true count for TC values of 2-5. For greater than five, remain at a multiplier of five, for one or lower, use a multiplier of one.

**Resplit Aces**: Not allowed.

**Blackjack on Split Aces**: Allowed.

**Hitting Split Aces**: Allowed.

**Soft Hand Doubling Variants**: The player can double on any soft hand.

**Late Surrender**: Not allowed.

**Doubling**: Player can double on any first two cards.

**Dealer Blackjack**: Player only loses original bet to a dealer blackjack.

**Reshuffle**: The dealer reshuffles when 75% of the cards have been dealt.

**Basic Strategy**: The tables for the basic strategy implemented here can be found [here](https://www.blackjackapprenticeship.com/blackjack-strategy-charts/).

**Player Bankroll** The player starts with $1000 and the betting unit is $10.

