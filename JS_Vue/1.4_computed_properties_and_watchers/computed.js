const objWithNest = Vue.createApp({
	data() {
		return {
			author: {
				first_name: 'John',
				last_name: 'Doe',
				books: [
					'Vue 2 - Advanced Guide',
					'Vue 3 - Basic Guide',
					'Vue 4 - The Mystery'
				]
			}
		}
	},
	computed: {
		isBooksExists() {
			// Optimize by no indicating if greater than or not.
			return this.author.books.length ? "Contains books" : "There are no published books."
		},
		dateNow() { // ! This won't refresh since it's not reactive dependency.
			// For this to be refreshed, we have to put this in a watched property.
			return Date.now()
		},
		author_name: { // Implement Getter and Setter.
			// Go to Console and navigate to vm.author_name to set and get the value of it.
			get() {
				return `${this.author.first_name} ${this.author.last_name}`
			},
			set(data) {
				const splitName = data.split(" ")
				this.author.first_name = splitName[0]
				this.author.last_name = splitName[1]
			}
		}
	}
})

const vm = objWithNest.mount("#computed-basics")