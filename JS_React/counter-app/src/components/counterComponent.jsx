import React, { Component } from 'react';

// ! You could do inline export declaration from the class itself.
export default class CounterC extends Component {
	// ! Contains Dynamic Data
	state = {
		count: 0,
		tags: [ 'sampleTag', 'sampleInstance', 'sample' ],
		imageUrl: 'https://picsum.photos/200'
	};

	render() {
		return (
			// ! Use React.Fragment Instead of DIV.
			<React.Fragment>
				<h1>Hello World!</h1>
				<span style={{ fontSize: 10, fontWeight: 'bold' }} className={this.getChangeBadgeProperties()}>
					Value of Current Instance is {this.formatCount()}
				</span>
				<img className="m-2" src={this.state.imageUrl} alt="" />
				<button onClick={this.handleIncrement} className="btn btn-secondary btn-sm">Increment Value</button>

				{/* ! Any value that renders from left side as true will render its content such as the string here.
                { !this.state.tags.length && "Please create a new tag!" }
                { this.renderTags() } */}

			</React.Fragment>
		);
	}

    handleIncrement() {
        // ! This DOES NOT Work.
        return console.log(`Increment Button Clicked: Current Value is ${this.state.count}`)
    }

	renderTags() {
		if (!this.state.tags.length) return 'There are no tags!';
		return <ul>{this.state.tags.map((tag) => <li key={tag}>{tag}</li>)}</ul>;
	}

	getChangeBadgeProperties() {
		let baseClasses = 'badge m-2 badge-';
		baseClasses += !this.state.count ? 'warning' : 'primary';
		return baseClasses;
	}

	formatCount() {
		const { count } = this.state;
		return !count ? 'Zero' : count;
	}
}

// export default CounterC;
