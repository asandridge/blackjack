# Card Counting Simulator

This program is designed to accurately imitate a real-life blackjack game, and to help estimate EV (expected value) for playing blackjack as a card counter.

To run the program:

    make compile

    make run

## Variable Rules

These rules can be updated by the user.

**Decks**: The number of decks in the shoe.

**H17**: Whether or not the dealer hits on a soft 17 or not.

**DAS**: Whether the player is allowed to double after split.

**Variants**: Whether to change basic strategy based on the true count.

**Counting Strategy**: What card counting technique to use.

**Blackjack Payout**: How much the player is payed upon receiving a blackjack.

**Resplit Limit**: The max number of decks a player can resplit to.

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